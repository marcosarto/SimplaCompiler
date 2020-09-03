#include "semantica.h"
#include "table.h"
#include <string.h>

#define LEN_ERR_MAX 180

int dentroCiclo = 0;
int totreturns = 0;

void evalType(Pnode n) {

    if (n->c1 != NULL)
        varDeclList(n->c1);

    if (n->c2 != NULL)
        funDeclList(n->c2);

    body(n->b, getGlobale());
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
        if (temp->value.sval[0] == '*')
            entry->pointer = 1;
        else
            entry->pointer = 0;
        int i = 0;
        while (temp->value.sval[i] == '*') {
            i++;
        }
        entry->nstars = i;
        entry->key = temp->value.sval + i;
        entry->classe = VAR;
        entry->tipo = tipo;
        entry->next = NULL;
        if (!insertInto(entry, table)) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "L'identificatore %s e' gia' dichiarato precedentemente\n", temp->value.sval);
            errSemantico(s, temp);
        }
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
                if (temp->c1->value.sval[0] == '*')
                    entryt->pointer = 1;
                else
                    entryt->pointer = 0;
                int j = 0;
                while (temp->c1->value.sval[j] == '*') {
                    j++;
                }
                entryt->nstars = j;
                entryt->key = temp->c1->value.sval + j;
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
        if (n->c1 != NULL)
            varDeclListInterno(n->c1, table);
        print(table);

        n = n->b;
    }
    //Controllo il body di ogni funzione
    while (originalN != NULL) {
        Table *tableFun = lookUp(originalN->c2->value.sval, getGlobale())->ambiente;
        body(originalN->c2->c1, tableFun);
        if(totreturns == 0 && originalN->c2->b->type!=VOIDE){
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "La funzione %s non copre tutti i possibili percorsi con return\n", originalN->c2->value.sval);
            errSemantico(s, originalN->c2->c1);
        }
        totreturns = 0;
        originalN = originalN->b;
    }
}

void body(Pnode n, Table *table) {
    while (n != NULL) {
        if (n->type == T_BREAK)
            breakStat(n, table);
        else {
            switch (n->value.ival) {
                case NASSIGN_STAT:
                    assignStat(n, table);
                    break;
                case NIF_STAT:
                    ifStat(n, table);
                    break;
                case NWHILE_STAT:
                    whileStat(n, table);
                    break;
                case NFOR_STAT:
                    forStat(n, table);
                    break;
                case NFUNC_CALL:
                    funcCall(n, table);
                    break;
                case NRETURN_STAT:
                    returnStat(n, table);
                    break;
                case NREAD_STAT:
                    readStat(n, table);
                    break;
            }
        }
        n = n->b;
    }
}

void readStat(Pnode n, Table *table) {
    Pnode temp = n->c1;
    while (temp != NULL) {
        if (lookUp(temp->value.sval, table) == NULL) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "Variabile %s del read fuori scope (%s) o non dichiarata\n", temp->value.sval,
                    table->scope);
            errSemantico(s, temp);
        } else if (lookUp(temp->value.sval, table)->classe != VAR && lookUp(temp->value.sval, table)->classe != PAR) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "Variabile %s del read di classe non consentita\n", temp->value.sval);
            errSemantico(s, temp);
        }
        temp = temp->b;
    }
}

void returnStat(Pnode n, Table *table) {
    totreturns++;
    HashType tipoFun = lookUp(table->scope, getGlobale())->tipo;
    if (n->c1 != NULL) {
        if (tipoFun != expr(n->c1, table))
            errSemantico("Tipo di ritorno diverso dal tipo della funzione\n", n);
    } else {
        if (tipoFun != VOIDE)
            errSemantico("Tipo di ritorno diverso dal tipo della funzione\n", n);
    }
}

void forStat(Pnode n, Table *table) {
    dentroCiclo = 1;
    if (lookUp(n->c1->value.sval, table) == NULL) {
        char *s = malloc(LEN_ERR_MAX);
        sprintf(s, "variabile del for %s non precedentemente dichiarata o fuori dallo scope %s\n",
                n->c1->value.sval, table->scope);
        errSemantico(s, n->c1);
    }
    if (lookUp(n->c1->value.sval, table)->classe != VAR && lookUp(n->c1->value.sval, table)->classe != PAR)
        errSemantico("la variabile del for di assegnamento non e' ne var ne par\n", n->c1);
    if (lookUp(n->c1->value.sval, table)->tipo != INTE)
        errSemantico("la variabile del for non e' di tipo intero, non e' consentito\n", n->c1);
    if (expr(n->c1->c1, table) != INTE)
        errSemantico("expr1 del for non e' di tipo intero, non e' consentito\n", n->c1->c1);
    if (expr(n->c1->c2, table) != INTE)
        errSemantico("expr2 del for non e' di tipo intero, non e' consentito\n", n->c1->c2);
    Pnode temp = n->c2;
    while (temp != NULL) {
        if (temp->type == T_NONTERMINAL && temp->value.ival == NASSIGN_STAT) {
            if (strcmp(temp->c1->value.sval, n->c1->value.sval) == 0)
                errSemantico("Il for ID non puo' essere usato come LHS di un assegnamento in stat list\n", temp);
        }
        temp = temp->b;
    }
    dentroCiclo = 0;
}

void whileStat(Pnode n, Table *table) {
    dentroCiclo = 1;
    if (expr(n->c1, table) != BOOLE)
        errSemantico("while stat senza condizione booleana\n", n->c1);
    dentroCiclo = 0;
}

void ifStat(Pnode n, Table *table) {
    if (expr(n->c1, table) != BOOLE)
        errSemantico("if stat senza condizione booleana\n", n->c1);

    int prebody = totreturns;
    body(n->c2,table);
    int ifsReturns = totreturns - prebody;
    int elsesReturns = 0;
    prebody = totreturns;
    if(n->c1->b != NULL){
        body(n->c1->b,table);
        elsesReturns = totreturns - prebody;
    }
    if(!(ifsReturns>0 && elsesReturns > 0))
        totreturns = totreturns - ifsReturns - elsesReturns;
}

void assignStat(Pnode n, Table *table) {
    if (lookUpCond(n->c1->value.sval, table, 0) == NULL) {
        char *s = malloc(LEN_ERR_MAX);
        sprintf(s, "variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
                n->c1->value.sval, table->scope);
        errSemantico(s, n);
        return;
    }
    if (lookUpCond(n->c1->value.sval, table, 0)->pointer && n->c1->value.sval[0] != '*') {
        if (n->c2->type == T_ID) {
            Entry *e1 = lookUpCond(n->c1->value.sval, table, 0);
            Entry *e2 = lookUpCond(n->c2->value.sval, table, 0);
            if (e2 == NULL) {
                char *s = malloc(LEN_ERR_MAX);
                sprintf(s, "variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
                        n->c2->value.sval, table->scope);
                errSemantico(s, n);
                return;
            }
            if (e1->nstars != e2->nstars) {
                char *s = malloc(LEN_ERR_MAX);
                sprintf(s, "i puntatori hanno livelli diversi, %s livello %d, %s livello %d\n", e1->key,
                        e1->nstars, e2->key, e2->nstars);
                errSemantico(s, n);
            }
        } else if (n->c2->type == T_ADDR) {
            Entry *e1 = lookUpCond(n->c1->value.sval, table, 0);
            Entry *e2 = lookUpCond(n->c2->c1->value.sval, table, 0);
            if (e2 == NULL) {
                char *s = malloc(LEN_ERR_MAX);
                sprintf(s, "variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
                        n->c2->c1->value.sval, table->scope);
                errSemantico(s, n);
                return;
            }
            if (e1->nstars != (e2->nstars + 1)) {
                char *s = malloc(LEN_ERR_MAX);
                sprintf(s, "i puntatori hanno livelli diversi, %s livello %d, %s livello %d\n", e1->key,
                        e1->nstars, e2->key, e2->nstars + 1);
                errSemantico(s, n);
            }
        } else {
            char *str = malloc(LEN_ERR_MAX);
            sprintf(str, "Un puntatore senza carattere '*' puo' essere solo assegnato ad un puntatore di pari livello o"
                         "livello inferiore con '&'\n");
            errSemantico(str, n);
        }
    } else {
        if (lookUp(n->c1->value.sval, table) == NULL) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "variabile %s non precedentemente dichiarata o fuori dallo scope %s\n",
                    n->c1->value.sval, table->scope);
            errSemantico(s, n);
            return;
        }
        if (lookUp(n->c1->value.sval, table)->classe != VAR && lookUp(n->c1->value.sval, table)->classe != PAR)
            errSemantico("la variabile di assegnamento non e' ne var ne par\n", n);

        HashType tipo = (lookUp(n->c1->value.sval, table))->tipo; //tipo var, da confrontare con expr
        HashType tipoExpr;
        tipoExpr = expr(n->c2, table);

        if (tipo != tipoExpr) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "variabile %s non compatbile con l'expr\n", n->c1->value.sval);
            errSemantico(s, n);
        }

    }
}

void breakStat(Pnode n, Table *table) {
    if (!dentroCiclo)
        errSemantico("istruzione break al di fuori di un ciclo\n", n);
}

HashType expr(Pnode n, Table *table) {
    HashType exprType;
    //Forse migliorabile se and e or vengono messi in una variabile a parte e in type metto solo tipo T_BOOL
    //Cosi anche gli altri, da guardare //todo
    if (n->type == T_AND || n->type == T_OR) {
        exprType = BOOLE;
        if (expr(n->c1, table) != exprType)
            errSemantico("Ramo sinistro del confronto and/or non booleano\n", n);
        if (boolterm(n->c2, table) != exprType)
            errSemantico("Ramo destro del confronto and/or non booleano\n", n);
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
            errSemantico("relTerm (>,<,==,>=,<=) di tipo non compatibile\n", n);
        return boolType;
    } else return relTerm(n, table);
}

HashType relTerm(Pnode n, Table *table) {
    HashType relType;
    //Controllo aggiuntivo n->c2!=NULL per differenziare il meno della negazione
    if (n->type == T_PLUS || (n->type == T_MINUS && n->c2 != NULL)) {
        relType = relTerm(n->c1, table);
        if (relType != INTE && relType != REALE)
            errSemantico("tipi incompatibili gli operatori matematici non consentono questa operazione\n", n);
        if (relType != lowTerm(n->c2, table))
            errSemantico("relterm lowterm (+,-) di tipo non compatibile\n", n);
        return relType;
    } else return lowTerm(n, table);
}

HashType lowTerm(Pnode n, Table *table) {
    HashType lowType;
    if (n->type == T_STAR || n->type == T_DIV) {
        lowType = lowTerm(n->c1, table);
        if (lowType != INTE && lowType != REALE)
            errSemantico("tipi incompatibili gli operatori matematici non consentono questa operazione\n", n);
        if (lowType != factor(n->c2, table))
            errSemantico("lowtype factor (*,/) di tipo non compatibile\n", n);
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
                errSemantico("unary_op tipo incompatibile\n", n);
        } else {
            factorType = factor(n->c1, table);
            if (factorType != BOOLE)
                errSemantico("unary_op tipo incompatibile\n", n);
        }
        return factorType;
    }
        //func_call
    else if (n->type == T_NONTERMINAL && n->value.ival == NFUNC_CALL) {
        return funcCall(n, table);
    }

        //id
    else if (n->type == T_ID) {
        Entry *e;
        e = lookUp(n->value.sval, table);

        if (e == NULL) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "variabile %s non dichiarata o fuori scope\n", n->value.sval);
            errSemantico(s, n);
        }
        factorType = e->tipo;
        return factorType;

    } else if (n->type == T_ADDR) {
        Entry *e;
        e = lookUp(n->c1->value.sval, table);

        if (e == NULL) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "variabile %s non dichiarata o fuori scope\n", n->value.sval);
            errSemantico(s, n);
        }
        factorType = e->tipo;
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
                if (expr(n->c1, table) != REALE)
                    errSemantico("Il casting di questi tipi non e' permesso\n", n->c1);
                return INTE;
                break;
            case T_REAL:
                if (expr(n->c1, table) != INTE)
                    errSemantico("Il casting di questi tipi non e' permesso\n", n->c1);
                return REALE;
                break;
        }
    }
        //cond_expr
    else if (n->type == T_NONTERMINAL && n->value.ival == NCOND_EXPR) {
        if (expr(n->b, table) != BOOLE)
            errSemantico("la condizione di if non e' booleana\n", n->b);
        factorType = expr(n->c1, table);
        if (factorType != expr(n->c2, table))
            errSemantico("i due branch dell'if sono di tipi diversi\n", n->c2);
        return factorType;
    }
        //(expr)
    else {
        return expr(n, table);
    }

}

HashType getHashTypeN(Pnode n, int ancheFunzioni) {
    HashType tipo = -1;
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
                errSemantico("Tipo di varList non consentito\n", n);
            break;
        default:
            if (ancheFunzioni)
                errSemantico("Tipo di funList non consentito\n", n);
            else
                errSemantico("Tipo di varList non consentito\n", n);
            break;
    }
    return tipo;
}

HashType funcCall(Pnode n, Table *table) {
    HashType factorType;

    //Restituisco il tipo del valore di ritorno della funzione
    Entry *funEntry = lookUp(n->c1->value.sval, getGlobale());
    if (funEntry == NULL) {
        char *s = malloc(LEN_ERR_MAX);
        sprintf(s, "funzione %s non definita precedentemente\n", n->c1->value.sval);
        errSemantico(s, n->c1);
    }
    factorType = funEntry->tipo;
    if (funEntry->classe != FUN) {
        char *s = malloc(LEN_ERR_MAX);
        sprintf(s, " %s non e' di tipo FUN\n", n->c1->value.sval);
        errSemantico(s, n->c1);
    }
    //Se ha argomenti
    if (n->c1->c1 != NULL) {
        Pnode temp = n->c1->c1;
        int nArgs = 0;
        do {
            nArgs++;
            temp = temp->b;
        } while (temp != NULL);

        if (nArgs != funEntry->nformali) {
            char *s = malloc(LEN_ERR_MAX);
            sprintf(s, "numero argomenti differenti dalla firma nella funzione %s\n", n->c1->value.sval);
            errSemantico(s, n->c1);
        }

        temp = n->c1->c1;
        for (int i = 0; i < nArgs; i++) {
            if (temp->type == T_ID) {
                Entry *e1 = lookUpCond(temp->value.sval, table, 0);

                int j = 0;
                while(temp->value.sval[j]=='*')
                    j++;

                if ((e1->nstars-j) != funEntry->dformali[i]->nstars) {
                    char *s = malloc(LEN_ERR_MAX);
                    sprintf(s, "i puntatori della funzione %s hanno livelli diversi, %s livello %d, %s livello %d\n",
                            funEntry->key, e1->key, e1->nstars, funEntry->dformali[i]->key,
                            funEntry->dformali[i]->nstars);
                    errSemantico(s, n);
                }
            }else if(temp->type==T_ADDR){

                Entry *e1 = lookUpCond(temp->c1->value.sval,table,0);

                if(e1->nstars+1!=(funEntry->dformali[i]->nstars)) {
                    char *s = malloc(LEN_ERR_MAX);
                    sprintf(s, "i puntatori della funzione %s hanno livelli diversi, %s livello %d, %s livello %d\n",
                            funEntry->key,e1->key,e1->nstars, funEntry->dformali[i]->key, funEntry->dformali[i]->nstars + 1);
                    errSemantico(s, n);
                }
            }else {
                if (funEntry->dformali[i]->tipo != expr(temp, table)) {
                    char *s = malloc(LEN_ERR_MAX);
                    sprintf(s, "tipo argomenti della funzione %s non compatibili con la firma\n", n->c1->value.sval);
                    errSemantico(s, n->c1);
                }
            }
            temp = temp->b;
        }
    }
    return factorType;
}

void errSemantico(char *s, Pnode n) {
    printf("Line %d: ErrSemantico, %s", n->linen, s);
    closeWriteToFile();
    exit(-2);
}

