#include "interprete.h"
#include "string.h"

#define MAX_INPUT 100

extern Ostackrecord *op;
extern Astack *ap, *aproot;
Pnode rootAST;
int funInterrupt = 0,toExit=0;

void runCode(Pnode root) {
    initRunStructure();
    initStringPool();

    rootAST = root;

    Astack as;
    as.startPoint = op;
    as.nObjs = 0;
    as.table = getGlobale();
    *ap = as;
    ap++;

    if (root->c1 != NULL)
        varDeclListex(root->c1);

    bodyex(root->b);

    printAStack();
    printStringPoolStructure();
}

void varDeclListex(Pnode n) {
    HashType tipo;
    tipo = getHashTypeN(n->c2, 0);

    Pnode temp = n->c1;
    while (temp) {
        Ostackrecord otemp;
        switch (tipo) {
            case INTE:
                otemp.tipo = INTE;
                break;
            case REALE:
                otemp.tipo = REALE;
                break;
            case BOOLE:
                otemp.tipo = BOOLE;
                break;
            case STRINGE:
                otemp.tipo = STRINGE;
                break;
        }
        *op = otemp;
        aumentaOp();
        temp = temp->b;
    }
    if (n->b != NULL) varDeclListex(n->b);
}

void bodyex(Pnode n) {
    while (n != NULL) {
        if(funInterrupt) return;
        if(n->type == T_BREAK)
            breakStatex(n);
        else {
            switch (n->value.ival) {
                case NASSIGN_STAT:
                    assignStatex(n);
                    break;
                case NIF_STAT:
                    ifStatex(n);
                    break;
                case NFOR_STAT:
                    forStatex(n);
                    break;
                case NWHILE_STAT:
                    whileStatex(n);
                    break;
                case NRETURN_STAT:
                    returnStatex(n);
                    return;
                case NFUNC_CALL:
                    funcCallex(n);
                    break;
                case NREAD_STAT:
                    readStatex(n);
                    break;
                case NWRITE_STAT:
                    writeStatex(n);
                    break;
            }
        }
        n = n->b;
    }
}

void whileStatex(Pnode n){
    do {
        exprex(n->c1);
        if ((op - 1)->val.bval == TRUE) {
            diminuisciOp();
            bodyex(n->c2);
        } else
            return;
    }while(1); //forse non e' considerata buona programmazione
}

void breakStatex(Pnode n){
    toExit = 1;
}

void assignStatex(Pnode n) {
    exprex(n->c2);
    cambiaValInStack(n->c1->value.sval);
}

void writeStatex(Pnode n) {
    Pnode temp = n->c2;
    while (temp != NULL) {
        exprex(temp);
        switch ((op - 1)->tipo) {
            case INTE:
                printf("%d", (op - 1)->val.ival);
                break;
            case REALE:
                printf("%f", (op - 1)->val.rval);
                break;
            case STRINGE:
                printf("%s", (op - 1)->val.sval);
                break;
            case BOOLE:
                printf("%s", (op - 1)->val.bval ? "true" : "false");
                break;
        }
        diminuisciOp();
        temp = temp->b;
    }
    if (n->c1->type == T_WRITELN) {
        printf("\n");
    }
}

void readStatex(Pnode n) {
    Pnode temp = n->c1;
    while (temp != NULL) {
        char str[MAX_INPUT];
        scanf("%s", str);
        switch (lookUp(temp->value.sval, (ap - 1)->table)->tipo) {
            case INTE:
                if (!isInt(str)) {
                    printf("Read stat %s e' intero, l'input e' invece di tipo non compatibile\n",
                           temp->value.sval);
                    errRunTime();
                } else {
                    Ostackrecord os;
                    Value val;
                    os.tipo = INTE;
                    val.ival = atoi(str);
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(temp->value.sval);
                }
                break;
            case REALE:
                if (!isReale(str)) {
                    printf("Read stat %s e' real, l'input e' invece di tipo non compatibile\n",
                           temp->value.sval);
                    errRunTime();
                } else {
                    Ostackrecord os;
                    Value val;
                    os.tipo = REALE;
                    val.rval = atof(str);
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(temp->value.sval);
                }
                break;
            case BOOLE:
                if (!isBool(str)) {
                    printf("Read stat %s e' boolean, l'input e' invece di tipo non compatibile\n",
                           temp->value.sval);
                    errRunTime();
                } else {
                    Ostackrecord os;
                    Value val;
                    os.tipo = BOOLE;
                    val.bval = str[0] == 'f' ? FALSE : TRUE;
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(temp->value.sval);
                }
                break;
            case STRINGE:
                if (0); //Se Ostack come prima riga errore, non so perche'
                Ostackrecord os;
                Value val;
                os.tipo = STRINGE;
                val.sval = addString(str);
                os.val = val;
                *op = os;
                aumentaOp();
                cambiaValInStack(temp->value.sval);
                break;
        }
        temp = temp->b;
    }
}

void forStatex(Pnode n) {

    exprex(n->c1->c1);
    cambiaValInStack(n->c1->value.sval);

    int uscita;
    do {
        exprex(n->c1->c2);

        uscita = 1;
        //Controllo se la variabile e' locale
        int Oid = getOid(n->c1->value.sval,(ap-1)->table);
        if (Oid != -1) {
            if (((ap - 1)->startPoint + Oid)->val.ival <= (op - 1)->val.ival) {
                uscita = 0;
            }
        } else {
            Oid = getOid(n->c1->value.sval, getGlobale());
            if (((aproot)->startPoint + Oid)->val.ival <= (op - 1)->val.ival) {
                uscita = 0;
            }

        }
        diminuisciOp();

        //Runno il corpo del for se uscita = 0;
        if (!uscita) {
            bodyex(n->c2);

            if(toExit)
                break;

            //Aumento di 1
            int prec = getValueVarStack(n->c1->value.sval).ival;
            prec++;
            Ostackrecord os;
            os.tipo = INTE;
            os.val.ival = prec;
            *op = os;
            aumentaOp();
            cambiaValInStack(n->c1->value.sval);
        }
    } while (uscita != 1);
    toExit = 0;
}

void ifStatex(Pnode n) {
    exprex(n->c1);
    int cond = (op - 1)->val.bval;
    diminuisciOp();
    if (cond) {
        bodyex(n->c2);
    } else {
        bodyex(n->c1->b);
    }
}

void cambiaValInStack(char *s) {
    //Controllo se la variabile e' locale
    int Oid = getOid(s,(ap-1)->table);
    if (Oid != -1) {
        ((ap - 1)->startPoint + Oid)->val = (op - 1)->val;
        diminuisciOp();
    }
        //E' globale e io non sono nel main
    else {
        Oid = getOid(s, getGlobale());
        ((aproot)->startPoint + Oid)->val = (op - 1)->val;
        diminuisciOp();
    }
}

void returnStatex(Pnode n) {
    funInterrupt = 1;
    if (n->c1 != NULL) {
        exprex(n->c1);
        (((ap - 2)->startPoint) + (ap - 2)->nObjs - 1)->val = (op - 1)->val;
        ap--;
        //Riaggiusto il puntatore op
        op = (ap - 1)->startPoint + (ap - 1)->nObjs;
    }
    else{
        ap--;
        op = (ap - 1)->startPoint + (ap - 1)->nObjs;
    }
}

void funcCallex(Pnode n) {
    //Creo uno slot sullo stack per metterci il valore di ritorno (se non void)
    if (lookUp(n->c1->value.sval, getGlobale())->tipo != VOIDE) {
        Ostackrecord ost;
        ost.tipo = lookUp(n->c1->value.sval, getGlobale())->tipo;
        *op = ost;
        aumentaOp();
    }

    Astack as;
    as.startPoint = op;
    as.nObjs = 0;
    as.table = lookUp(n->c1->value.sval, getGlobale())->ambiente;


    //Creo gli slot nello stack che conterranno i parametri formali
    Entry *e = lookUp(n->c1->value.sval, getGlobale());
    Pnode temp = n->c1->c1;
    for (int i = 0; i < e->nformali; i++) {
        Ostackrecord os;
        os.tipo = e->dformali[i]->tipo;
        *op = os;
        op++;
        //Computo l'expr passata come argomento
        exprex(temp);
        (op-2)->val = (op-1)->val;
        diminuisciOp();
        temp = temp->b;
    }

    *ap = as;
    ap++;
    //Spiega questa parte nella presentazione (necessita' ap precedente)
    for(int i = 0; i < e->nformali; i++)
        (ap-1)->nObjs++;
    //Creo sullo stack le variabili locali della funzione
    int exit = 0;
    Pnode funPointer = rootAST->c2;
    do {
        if (strcmp(funPointer->c2->value.sval, n->c1->value.sval) == 0) {
            exit = 1;
            if (funPointer->c1 != NULL)
                varDeclListex(funPointer->c1);
        }
        if (exit != 1) funPointer = funPointer->b;
    } while (exit != 1);
    //Eseguo il corpo della funzione chiamata, sullo stack c'e' gia tutto
    bodyex(funPointer->c2->c1);
    if(funInterrupt)
        funInterrupt = 0;
    //Entro qui solo se sono in una funzione void senza return esplicito
    else {
        ap--;
        op = (ap - 1)->startPoint + (ap - 1)->nObjs;
    }
}

void exprex(Pnode n) {
    Ostackrecord os;
    switch (n->type) {
        case T_AND:
            exprex(n->c1);
            if (!(op - 1)->val.bval) {
                os.val.bval = FALSE;
            }else{
                booltermex(n->c2);
                os.val.bval = (op - 1)->val.bval;
                diminuisciOp();
            }
            os.tipo = BOOLE;
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_OR:
            exprex(n->c1);
            if((op-1)->val.bval) {
                os.val.bval = TRUE;
            }else {
                booltermex(n->c2);
                os.val.bval = (op - 1)->val.bval;
                diminuisciOp();
            }
            diminuisciOp();
            os.tipo = BOOLE;
            *op = os;
            aumentaOp();
            break;
        default:
            booltermex(n);
    }
}

void booltermex(Pnode n) {
    Ostackrecord os;
    switch (n->type) {
        case T_EQU:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            //Forse c'e' un modo meno lungo
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival == (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval == (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval == (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval == (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_NEQ:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival != (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval != (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval != (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval != (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_GRT:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival > (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval > (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval > (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval > (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_GEQ:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival >= (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval >= (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval >= (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval >= (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_LSS:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival < (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval < (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval < (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval < (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_LEQ:
            relTermex(n->c1);
            relTermex(n->c2);
            os.tipo = BOOLE;
            switch ((op - 2)->tipo) {
                case INTE:
                    os.val.bval = (op - 2)->val.ival <= (op - 1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op - 2)->val.rval <= (op - 1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op - 2)->val.sval <= (op - 1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op - 2)->val.bval <= (op - 1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            relTermex(n);
    }
}

void relTermex(Pnode n) {
    Ostackrecord os;
    switch (n->type) {
        case T_PLUS:
            relTermex(n->c1);
            lowTermex(n->c2);
            if ((op - 2)->tipo == INTE) {
                os.tipo = INTE;
                os.val.ival = (op - 2)->val.ival + (op - 1)->val.ival;
            } else {
                os.tipo = REALE;
                os.val.rval = (op - 2)->val.rval + (op - 1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_MINUS:
            if (n->c2 != NULL) {
                relTermex(n->c1);
                lowTermex(n->c2);
                if ((op - 2)->tipo == INTE) {
                    os.tipo = INTE;
                    os.val.ival = (op - 2)->val.ival - (op - 1)->val.ival;
                } else {
                    os.tipo = REALE;
                    os.val.rval = (op - 2)->val.rval - (op - 1)->val.rval;
                }
                diminuisciOp();
                diminuisciOp();
                *op = os;
                aumentaOp();
            } else {
                lowTermex(n);
            }
            break;
        default:
            lowTermex(n);
    }
}

void lowTermex(Pnode n) {
    Ostackrecord os;
    switch (n->type) {
        case T_STAR:
            lowTermex(n->c1);
            factorex(n->c2);
            if ((op - 2)->tipo == INTE) {
                os.tipo = INTE;
                os.val.ival = (op - 2)->val.ival * (op - 1)->val.ival;
            } else {
                os.tipo = REALE;
                os.val.rval = (op - 2)->val.rval * (op - 1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_DIV:
            lowTermex(n->c1);
            factorex(n->c2);
            if ((op - 2)->tipo == INTE) {
                os.tipo = INTE;
                os.val.ival = (op - 2)->val.ival / (op - 1)->val.ival;
            } else {
                os.tipo = REALE;
                os.val.rval = (op - 2)->val.rval / (op - 1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            factorex(n);
    }
}

void factorex(Pnode n) {
    Ostackrecord os;
    switch (n->type) {
        case T_INTCONST:
            os.tipo = INTE;
            os.val = n->value;
            *op = os;
            aumentaOp();
            break;
        case T_REALCONST:
            os.tipo = REALE;
            os.val = n->value;
            *op = os;
            aumentaOp();
            break;
        case T_BOOLCONST:
            os.tipo = BOOLE;
            os.val = n->value;
            *op = os;
            aumentaOp();
            break;
        case T_STRCONST:
            os.tipo = STRINGE;
            Value toAdd;
            toAdd.sval = addStringLiteral(n->value.sval);
            os.val = toAdd;
            *op = os;
            aumentaOp();
            break;
        case T_MINUS:
            factorex(n->c1);
            if ((op - 1)->tipo == INTE)
                (op - 1)->val.ival = -((op - 1)->val.ival);
            else
                (op - 1)->val.rval = -((op - 1)->val.rval);
            break;
        case T_NOT:
            factorex(n->c1);
            if ((op - 1)->val.bval == FALSE)
                (op - 1)->val.bval = TRUE;
            else
                (op - 1)->val.bval = FALSE;
            break;
        case T_NONTERMINAL:
            if (n->value.ival == NFUNC_CALL) {
                funcCallex(n);
            } else if (n->value.ival == NCOND_EXPR) {
                exprex(n->b);
                if ((op - 1)->val.bval) {
                    diminuisciOp();
                    exprex(n->c1);
                } else {
                    diminuisciOp();
                    exprex(n->c2);
                }
            }
            break;
        case T_ID:
            if (getOid(n->value.sval, (ap - 1)->table) != -1) {
                os.tipo = lookUp(n->value.sval, (ap - 1)->table)->tipo;
                os.val = ((ap - 1)->startPoint + getOid(n->value.sval,(ap-1)->table))->val;
                *op = os;
                aumentaOp();
            } else {
                os.tipo = lookUp(n->value.sval, getGlobale())->tipo;
                os.val = ((aproot)->startPoint + getOid(n->value.sval, getGlobale()))->val;
                *op = os;
                aumentaOp();
            }
            break;
        case T_INTEGER:
            exprex(n->c1);
            (op - 1)->val.ival = (int) (op - 1)->val.rval;
            break;
        case T_REAL:
            exprex(n->c1);
            (op - 1)->val.rval = (op - 1)->val.ival;
            break;
        default:
            exprex(n);
            break;
    }
}

void aumentaOp() {
    op++;
    (ap - 1)->nObjs++;
}

void diminuisciOp() {
    op--;
    (ap - 1)->nObjs--;
}

int isInt(char *s) {
    int i = 0,almenoUno=0;
    if(s[i]=='-')
        i++;

    for (i ; i < strlen(s); i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return 0;
        else
            almenoUno = 1;
    }
    if(almenoUno)
        return 1;
    else return 0;
}

int isReale(char *s) {
    int i = 0;
    if(s[i]=='-')
        i++;

    int almenoUno = 0, punto = 0, almenoUnoDec = 0;
    for (i; i < strlen(s); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            if (s[i] == '.' && almenoUno && !punto)
                punto = 1;
            else
                return 0;
        } else {
            if (punto)
                almenoUnoDec = 1;
            else
                almenoUno = 1;
        }
    }
    if (almenoUno && punto && almenoUnoDec)
        return 1;
    return 0;
}

int isBool(char *s) {
    if (strcmp(s, "true") == 0 || strcmp(s, "false") == 0)
        return 1;
    return 0;
}

Value getValueVarStack(char *s) {
    //Controllo se la variabile e' locale
    int Oid = getOid(s, (ap - 1)->table);
    if (Oid != -1) {
        return ((ap - 1)->startPoint + Oid)->val;
    }
        //E' globale e io non sono nel main
    else {
        Oid = getOid(s, getGlobale());
        return ((aproot)->startPoint + Oid)->val;
    }
}

void errRunTime() {
    closeWriteToFile();
    exit(-1);
}