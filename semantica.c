#include "semantica.h"
#include "table.h"

void evalType(Pnode n) {
    switch (n->type) {
        case T_NONTERMINAL:
            switch (n->value.ival) {
                case NPROGRAM:
                    if(n->c1!=NULL)
                        varDeclList(n->c1);

                    if(n->c2!=NULL)
                        funDeclList(n->c2);

                    body(n->b,getGlobale());

                    break;
            }
    }
}

void varDeclList(Pnode n) {
    varDeclListInterno(n,getGlobale());
}
//Una specie di overload per differenziare le tabelle,
//era stata scelta una modalita' implementativa che ora non e'
//bellissima da gestiere, cambiare se viene in mente altro
void varDeclListInterno(Pnode n,Table *table){
    HashType tipo;

    tipo = getHashTypeN(n->c2,0);

    Pnode temp = n->c1;
    while (temp) {
        Entry *entry = malloc(sizeof(Entry));
        entry->key = temp->value.sval;
        entry->tipo = tipo;
        entry->next = NULL;
        if (!insertInto(entry,table))
            printf("ERRSEMANTICO L'identificatore %s e' gia' dichiarato precedentemente\n", temp->value.sval);
        temp = temp->b;
    }

    if (n->b != NULL) varDeclList(n->b);
}

void funDeclList(Pnode n){
    //Creo l'entry nella tabella principale per le funzione con i loro parametri
    char *nomeF;
    Table *table;
    do {
        Entry *entry = malloc(sizeof(Entry));
        nomeF = entry->key = n->c2->value.sval;
        HashType tipo = getHashTypeN(n->c2->b, 1);
        entry->tipo = tipo;
        entry->classe = FUN;
        entry->ambiente = creaAmbiente();
        table = entry->ambiente; //tabella locale
        Pnode temp = n->c2->c2;
        if (temp != NULL) {
            temp = temp->c1;
            int i = 0;
            while (temp != NULL) {
                Entry *entryt = malloc(sizeof(Entry));
                entryt->key = temp->c1->value.sval;
                entryt->classe = PAR;
                HashType tipot = getHashTypeN(temp->c2, 0);
                entryt->tipo = tipot;
                entryt->next = NULL;
                insertInto(entryt, entry->ambiente);
                entry->dformali[i] = entryt;
                temp = temp->b;
                i++;
            }

            entry->nformali = i;
        } else
            entry->nformali = 0;

        entry->next = NULL;
        insert(entry);
        assignScopeName(nomeF,table);

        //Gestisco le variabili dichiarate all'interno della tabella della funzione
        varDeclListInterno(n->c1, table);
        printf("TABELLA INTERNA DI %s\n", nomeF);
        print(table);
        n = n->b;
    }while(n!=NULL);

    //TODO BODY IN N->C2->C1 PER OGNUNA

}

void body(Pnode n,Table *table){
    while(n!=NULL) {
        switch (n->value.ival) {
            case NASSIGN_STAT:
                assignStat(n, table);
                break;
        }
        n = n->b;
    }
}


void assignStat(Pnode n,Table *table){
    if(lookUp(n->c1->value.sval,table)==NULL){
        printf("ERRSEMANTICO variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
                n->c1->value.sval,table->scope);
        return;
    }
    HashType tipo = (lookUp(n->c1->value.sval,table))->tipo; //tipo var, da confrontare con expr
    HashType tipoExpr = expr(n->c2);
    if(tipo != tipoExpr)
        printf("ERRSEMANTICO variabile %s non compatbile con l'expr\n",n->c1->value.sval);

}

HashType expr(Pnode n){
    HashType exprType;
    //Forse migliorabile se and e or vengono messi in una variabile a parte e in type metto solo tipo T_BOOL
    //Cosi anche gli altri, da guardare
    if(n->type == T_AND || n->type == T_OR) {
        exprType = BOOLE;
        if(expr(n->c1)!=exprType)
            printf("Errore semantico, espressioni di tipi non compatibili");
        if(boolterm(n->c2)!=exprType)
            printf("Errore semantico boolterm di tipo non compatibile");
        return exprType;
    }

    else return boolterm(n);
}

HashType boolterm(Pnode n){
    HashType boolType;
    if(n->type == T_EQU
    ||n->type == T_NEQ
    ||n->type == T_GRT
    ||n->type == T_GEQ
    ||n->type == T_LSS
    ||n->type == T_LEQ){
        boolType = BOOLE;
        if(relTerm(n->c1)!=relTerm(n->c2))
            printf("Errore semantico relTerm di tipo non compatibile");
        return boolType;
    }

    else return relTerm(n);
}

HashType relTerm(Pnode n){
    HashType relType;
    if(n->type==T_PLUS||(n->type==T_MINUS&&n->c2!=NULL)){
        relType = relTerm(n->c1);
        if(relType!=lowTerm(n->c2))
            printf("Errore semantico relterm lowterm di tipo non compatibile");
        return relType;
    }
    else return lowTerm(n);
}

HashType lowTerm(Pnode n){
    HashType lowType;
    if(n->type==T_STAR||n->type==T_DIV){
        lowType = lowTerm(n->c1);
        if(lowType!=factor(n->c2))
            printf("Erorre semantico lowtype factor di tipo non compatibile");
        return lowType;
    }
    else return factor(n);
}

HashType factor(Pnode n){
    HashType factorType;
    //unary_op
    if(n->type==T_MINUS||n->type==T_NOT){
        if(n->type==T_MINUS){
            factorType = factor(n->c1);
            if(factorType!=INTE&&factorType!=REALE)
                printf("Errore semantico unary_op tipo incompatibile");
        }
        else{
            factorType = factor(n->c1);
            if(factorType!=BOOLE)
                printf("Errore semantico unary_op tipo incompatibile");
        }
        return factorType;
    }
    //id o func_call
    else if(n->type==T_ID){
        //func_call
        if(n->c1!=NULL){
            //Restituisco il tipo del valore di ritorno della funzione
            //todo controlla opt_expr_list
            factorType = lookUp(n->value.sval,getGlobale())->tipo;
        }
        //id
        else{
            //todo non va bene getglobale quando sono nel body di una funzione
            factorType = lookUp(n->value.sval,getGlobale())->tipo;
        }
        return factorType;
    }
    //const
    else if(n->type==T_INTCONST
            ||n->type==T_STRCONST
            ||n->type==T_BOOLCONST
            ||n->type==T_REALCONST){
        switch (n->type) {
            case T_INTCONST:
                return INTE;
                break;
            case T_REALCONST:
                return REALE;
                break;
            case T_BOOLCONST:
                return BOOLE;
                break;
            case T_STRCONST:
                return STRINGE;
                break;
        }
    }
    //cast
    //Abbastanza brutto, cambia se c'e' tempo
    else if(n->type==T_INTEGER||n->type==T_REAL){
        switch (n->type) {
            case T_INTEGER:
                return INTE;
                break;
            case T_REAL:
                return REALE;
                break;
        }
    }
    //cond_expr
    else if(n->value.ival==NCOND_EXPR){
        if(expr(n->c1)!=BOOLE)
            printf("ERRSEMANTICO la condizione di if non e' booleana");
    }
    //(expr)
    else{

    }

}

HashType getHashTypeN(Pnode n,int ancheFunzioni){ //aggiunto n per conflitto, risolvi nome dopo
    HashType tipo = -1; //Cosa fare se qui errore? forse chiudo tutto, da chiedere
    switch (n->type) {
        case T_INTEGER:
            tipo = INTE;
            break;
        case T_REAL:
            tipo = REALE;
            break;
        case T_STRING:
            tipo = STRINGE;
            break;
        case T_BOOLEAN:
            tipo = BOOLE;
            break;
        case T_VOID:
            if(ancheFunzioni)
                tipo = VOIDE;
            else
                printf("ERRSEMANTICO Tipo di varList non consentito");
            break;
        default:
            if(ancheFunzioni)
                printf("ERRSEMANTICO Tipo di funList non consentito");
            else
                printf("ERRSEMANTICO Tipo di varList non consentito");
            break;
    }
    return tipo;
}
