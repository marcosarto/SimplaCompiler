#include "semantica.h"
#include "table.h"
#include <string.h>
void evalType(Pnode n) {
    switch (n->type) {
        case T_NONTERMINAL:
            switch (n->value.ival) {
                case NPROGRAM:
                    if (n->c1 != NULL)
                        varDeclList(n->c1);

                    if (n->c2 != NULL)
                        funDeclList(n->c2);

                    body(n->b, getGlobale());

                    break;
            }
    }
}

void varDeclList(Pnode n) {
    varDeclListInterno(n, getGlobale());
}

//Una specie di overload per differenziare le tabelle,
//era stata scelta una modalita' implementativa che ora non e'
//bellissima da gestiere, cambiare se viene in mente altro
void varDeclListInterno(Pnode n, Table *table) {
    HashType tipo;

    tipo = getHashTypeN(n->c2, 0);

    Pnode temp = n->c1;
    while (temp) {
        Entry *entry = malloc(sizeof(Entry));
        entry->key = temp->value.sval;
        entry->classe = VAR;
        entry->tipo = tipo;
        entry->next = NULL;
        if (!insertInto(entry, table))
            printf("ERRSEMANTICO L'identificatore %s e' gia' dichiarato precedentemente\n", temp->value.sval);
        temp = temp->b;
    }

    if (n->b != NULL) varDeclList(n->b);
}

void funDeclList(Pnode n) {
    //Creo l'entry nella tabella principale per le funzione con i loro parametri
    char *nomeF;
    Table *table;
    Pnode originalN = n;
    while (n != NULL) {
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
        assignScopeName(nomeF, table);

        //Gestisco le variabili dichiarate all'interno della tabella della funzione
        if(n->c1!=NULL)
            varDeclListInterno(n->c1, table);
        printf("TABELLA INTERNA DI %s\n", nomeF);
        print(table);

        n = n->b;
    }
    //Controllo il body di ogni funzione
    while (originalN != NULL) {
        Table *tableFun = lookUp(originalN->c2->value.sval,getGlobale())->ambiente;
        body(originalN->c2->c1, tableFun);
        originalN = originalN->b;
    }
}

void body(Pnode n, Table *table) {
    while (n != NULL) {
        switch (n->value.ival) {
            case NASSIGN_STAT:
                assignStat(n, table);
                break;
            case NIF_STAT:
                ifStat(n,table);
                break;
            case NWHILE_STAT:
                whileStat(n,table);
                break;
            case NFOR_STAT:
                forStat(n,table);
                break;
            case NRETURN_STAT:
                returnStat(n,table);
                break;
            case NREAD_STAT:
                readStat(n,table);
                break;
        }
        n = n->b;
    }
}

void readStat(Pnode n, Table *table){
    Pnode temp = n->c1;
    while(temp!=NULL) {
        if (lookUp(n->c1->value.sval, table) == NULL) {
            printf("ERRSEMANTICO Variabile %s del read fuori scope (%s) o non dichiarata\n",n->c1->value.sval,table->scope);
        }
        else if (lookUp(n->c1->value.sval, table)->classe != VAR && lookUp(n->c1->value.sval, table)->classe != PAR) {
            printf("ERRSEMANTICO Variabile %s del read di classe non consentita\n",n->c1->value.sval);
        }
        temp = temp->b;
    }
}

void returnStat(Pnode n, Table *table){
    HashType tipoFun = lookUp(table->scope,getGlobale())->tipo;
    if(n->c1!=NULL){
        if(tipoFun!=expr(n->c1,table))
            printf("Tipo di ritorno diverso dal tipo della funzione\n");
    }
    else{
        if(tipoFun!=VOIDE)
            printf("Tipo di ritorno diverso dal tipo della funzione\n");
    }
}

void forStat(Pnode n, Table *table){
    if (lookUp(n->b->value.sval, table) == NULL) {
        printf("ERRSEMANTICO variabile del for %s non precedentemente dichiarata o fuori dallo scope %s\n",
               n->b->value.sval, table->scope);
        return;
    }
    if(lookUp(n->b->value.sval, table)->classe!=VAR&&lookUp(n->b->value.sval, table)->classe!=PAR)
        printf("ERRSEMANTICO la variabile del for di assegnamento non e' ne var ne par\n");
    if(lookUp(n->b->value.sval, table)->tipo!=INTE)
        printf("ERRSEMANTICO la variabile del for non e' di tipo intero, non e' consentito\n");
    if(expr(n->b->b,table)!=INTE)
        printf("ERRSEMANTICO expr1 del for non e' di tipo intero, non e' consentito\n");
    if(expr(n->c1,table)!=INTE)
        printf("ERRSEMANTICO expr2 del for non e' di tipo intero, non e' consentito\n");
    Pnode temp = n->c2;
    while(temp!=NULL){
        if(temp->type == T_NONTERMINAL && temp->value.ival==NASSIGN_STAT){
            if(strcmp(temp->c1->value.sval,n->b->value.sval)==0)
                printf("ERRSEMANTICO Il for ID non puo' essere usato come LHS di un assegnamento in stat list\n");
        }
        temp = temp->b;
    }
}

void whileStat(Pnode n, Table *table){
    if(expr(n->c1,table)!=BOOLE)
        printf("ERRSEMANTICO while stat senza condizione booleana\n");
}

void ifStat(Pnode n, Table *table){
    if(expr(n->c1,table)!=BOOLE)
        printf("ERRSEMANTICO if stat senza condizione booleana\n");
}

void assignStat(Pnode n, Table *table) {
    if (lookUp(n->c1->value.sval, table) == NULL) {
        printf("ERRSEMANTICO variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
               n->c1->value.sval, table->scope);
        return;
    }

    if(lookUp(n->c1->value.sval, table)->classe!=VAR&&lookUp(n->c1->value.sval, table)->classe!=PAR)
        printf("ERRSEMANTICO la variabile di assegnamento non e' ne var ne par\n");

    HashType tipo = (lookUp(n->c1->value.sval, table))->tipo; //tipo var, da confrontare con expr
    HashType tipoExpr = expr(n->c2, table);
    if (tipo != tipoExpr)
        printf("ERRSEMANTICO variabile %s non compatbile con l'expr\n", n->c1->value.sval);

}

HashType expr(Pnode n, Table *table) {
    HashType exprType;
    //Forse migliorabile se and e or vengono messi in una variabile a parte e in type metto solo tipo T_BOOL
    //Cosi anche gli altri, da guardare //todo
    if (n->type == T_AND || n->type == T_OR) {
        exprType = BOOLE;
        if (expr(n->c1, table) != exprType)
            printf("Errore semantico, espressioni di tipi non compatibili\n");
        if (boolterm(n->c2, table) != exprType)
            printf("Errore semantico boolterm di tipo non compatibile\n");
        return exprType;
    } else return boolterm(n, table);
}

HashType boolterm(Pnode n, Table *table) {
    HashType boolType;
    if (n->type == T_EQU
        || n->type == T_NEQ
        || n->type == T_GRT
        || n->type == T_GEQ
        || n->type == T_LSS
        || n->type == T_LEQ) {
        boolType = BOOLE;
        if (relTerm(n->c1, table) != relTerm(n->c2, table))
            printf("Errore semantico relTerm di tipo non compatibile\n");
        return boolType;
    } else return relTerm(n, table);
}

HashType relTerm(Pnode n, Table *table) {
    HashType relType;
    //Controllo aggiuntivo n->c2!=NULL per differenziare il meno della negazione
    if (n->type == T_PLUS || (n->type == T_MINUS && n->c2 != NULL)) {
        relType = relTerm(n->c1, table);
        if (relType != lowTerm(n->c2, table))
            printf("ERRSEMANTICO relterm lowterm di tipo non compatibile\n");
        return relType;
    } else return lowTerm(n, table);
}

HashType lowTerm(Pnode n, Table *table) {
    HashType lowType;
    if (n->type == T_STAR || n->type == T_DIV) {
        lowType = lowTerm(n->c1, table);
        if (lowType != factor(n->c2, table))
            printf("Erorre semantico lowtype factor di tipo non compatibile\n");
        return lowType;
    } else return factor(n, table);
}

HashType factor(Pnode n, Table *table) {
    HashType factorType;
    //unary_op
    if (n->type == T_MINUS || n->type == T_NOT) {
        if (n->type == T_MINUS) {
            factorType = factor(n->c1, table);
            if (factorType != INTE && factorType != REALE)
                printf("Errore semantico unary_op tipo incompatibile\n");
        } else {
            factorType = factor(n->c1, table);
            if (factorType != BOOLE)
                printf("Errore semantico unary_op tipo incompatibile\n");
        }
        return factorType;
    }
        //func_call
    else if (n->type == T_NONTERMINAL && n->value.ival == NFUNC_CALL) {
        //Restituisco il tipo del valore di ritorno della funzione
        Entry *funEntry = lookUp(n->c1->value.sval, getGlobale());
        if (funEntry == NULL)
            printf("ERRSEMANTICO funzione %s non definita precedentemente\n", n->c1->value.sval);
        factorType = funEntry->tipo;
        if (funEntry->classe != FUN)
            printf("ERRSEMANTICO %s non e' di tipo FUN\n", n->c1->value.sval);
        //Se ha argomenti
        if (n->c1->c1 != NULL) {
            Pnode temp = n->c1->c1;
            int nArgs = 0;
            do {
                nArgs++;
                temp = temp->b;
            } while (temp != NULL);
            //Non pulitissimo ma impedisce il crash in caso di chiamata errata di una funzione
            if (nArgs != funEntry->nformali)
                printf("ERRSEMANTICO numero argomenti differenti dalla firma nella funzione %s\n", n->c1->value.sval);
            else{
                Pnode temp = n->c1->c1;
                for(int i=0;i<nArgs;i++){
                    if (funEntry->dformali[i]->tipo != expr(temp, table))
                        printf("ERRSEMANTICO tipo argomenti della funzione %s non compatibili con la firma\n", n->c1->value.sval);
                    temp = temp->b;
                }
            }
        }
        return factorType;
    }

        //id
    else if (n->type == T_ID) {
        factorType = lookUp(n->value.sval, table)->tipo;
        return factorType;
    }
        //const
        //Abbastanza brutto, cambia se c'e' tempo
    else if (n->type == T_INTCONST
             || n->type == T_STRCONST
             || n->type == T_BOOLCONST
             || n->type == T_REALCONST) {
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
    else if (n->type == T_INTEGER || n->type == T_REAL) {
        switch (n->type) {
            case T_INTEGER:
                if(expr(n->c1,table)!=REALE)
                    printf("ERRSEMANTICO Il casting di questi tipi non e' permesso\n");
                return INTE;
                break;
            case T_REAL:
                if(expr(n->c1,table)!=INTE)
                    printf("ERRSEMANTICO Il casting di questi tipi non e' permesso\n");
                return REALE;
                break;
        }
    }
        //cond_expr
    else if (n->type == T_NONTERMINAL && n->value.ival == NCOND_EXPR) {
        if (expr(n->c1, table) != BOOLE)
            printf("ERRSEMANTICO la condizione di if non e' booleana\n");
        factorType = expr(n->c1->c1,table);
        if(factorType!=expr(n->c1->c2,table))
            printf("ERRSEMANTICO i due branch dell'if sono di tipi diversi\n");
        return factorType;
    }
        //(expr)
    else {
        return expr(n, table);
    }

}

HashType getHashTypeN(Pnode n, int ancheFunzioni) { //aggiunto n per conflitto, risolvi nome dopo
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
            if (ancheFunzioni)
                tipo = VOIDE;
            else
                printf("ERRSEMANTICO Tipo di varList non consentito\n");
            break;
        default:
            if (ancheFunzioni)
                printf("ERRSEMANTICO Tipo di funList non consentito\n");
            else
                printf("ERRSEMANTICO Tipo di varList non consentito\n");
            break;
    }
    return tipo;
}
