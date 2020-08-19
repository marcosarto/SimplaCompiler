#include "interprete.h"
#include "string.h"
#define MAX_INPUT 100

extern Ostackrecord *op;
extern Astack *ap, *aproot;
Pnode rootAST;

void runCode(Pnode root) {
    initRunStructure();

    rootAST = root;

    Astack as;
    as.startPoint = op;
    as.nObjs = 0;
    *ap = as;
    ap++;

    if (root->c1 != NULL)
        varDeclListex(root->c1);

    bodyex(root->b, getGlobale());

    printAStack();
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

void createRA(char *funName) {
    Entry *e = lookUp(funName, getGlobale());
    for (int i = 0; i < e->nformali; i++) {
        Ostackrecord os;
        os.tipo = e->dformali[i]->tipo;
        *op = os;
        aumentaOp();
    }
}

void bodyex(Pnode n, Table *table) {
    while (n != NULL) {
        switch (n->value.ival) {
            case NASSIGN_STAT:
                assignStatex(n, table);
                break;
            case NIF_STAT:
                ifStatex(n,table);
                break;
            case NFOR_STAT:
                forStatex(n,table);
                break;
            case NRETURN_STAT:
                returnStatex(n, table);
                return;
            case NFUNC_CALL:
                funcCallex(n,table);
                break;
            case NREAD_STAT:
                readStatex(n,table);
                break;
            case NWRITE_STAT:
                writeStatex(n,table);
                break;
        }
        n = n->b;
    }
}

void assignStatex(Pnode n, Table *table) {
    exprex(n->c2, table);
    cambiaValInStack(n->c1->value.sval,table);
}

void writeStatex(Pnode n,Table *table){
    Pnode temp = n->c2;
    while(temp!=NULL){
        exprex(temp,table);
        switch ((op-1)->tipo) {
            case INTE:
                printf("%d",(op-1)->val.ival);
                break;
            case REALE:
                printf("%f",(op-1)->val.rval);
                break;
            case STRINGE:
                printf("%s",(op-1)->val.sval);
                break;
            case BOOLE:
                printf("%s",(op-1)->val.bval?"true":"false");
                break;
        }
        diminuisciOp();
        temp = temp->b;
    }
    if(n->c1->type==T_WRITELN){
        printf("\n");
    }
}

void readStatex(Pnode n,Table *table){
    Pnode temp = n->c1;
    while(temp!=NULL){
        char str[MAX_INPUT];
        scanf("%s",str);
        switch (lookUp(n->c1->value.sval,table)->tipo) {
            case INTE:
                if(!isInt(str)) {
                    printf("Read stat %s e' intero, l'input e' invece di tipo non compatibile\n",
                                      n->c1->value.sval);
                    errRunTime();
                }else{
                    Ostackrecord os;
                    Value val;
                    os.tipo = INTE;
                    val.ival = atoi(str);
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(n->c1->value.sval,table);
                }
                break;
            case REALE:
                if(!isReale(str)) {
                    printf("Read stat %s e' real, l'input e' invece di tipo non compatibile\n",
                           n->c1->value.sval);
                    errRunTime();
                }else{
                    Ostackrecord os;
                    Value val;
                    os.tipo = REALE;
                    val.rval = atof(str);
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(n->c1->value.sval,table);
                }
                break;
            case BOOLE:
                if(!isBool(str)) {
                    printf("Read stat %s e' boolean, l'input e' invece di tipo non compatibile\n",
                           n->c1->value.sval);
                    errRunTime();
                }else{
                    Ostackrecord os;
                    Value val;
                    os.tipo = BOOLE;
                    val.bval = str[0]=='f'?FALSE:TRUE;
                    os.val = val;
                    *op = os;
                    aumentaOp();
                    cambiaValInStack(n->c1->value.sval,table);
                }
                break;
            case STRINGE:
                if(0); //Se Ostack come prima riga errore, non so perche'
                Ostackrecord os;
                Value val;
                os.tipo = STRINGE;
                val.sval = newstring(str);
                os.val = val;
                *op = os;
                aumentaOp();
                cambiaValInStack(n->c1->value.sval,table);
                break;
        }
        temp = temp->b;
    }
}

void forStatex(Pnode n,Table *table){

    exprex(n->b->b,table);
    cambiaValInStack(n->b->value.sval,table);

    int uscita;
    do {
        exprex(n->c1, table);

        uscita = 1;
        //Controllo se la variabile e' locale
        int Oid = getOid(n->b->value.sval, table);
        if (Oid != -1) {
            if (((ap - 1)->startPoint + Oid)->val.ival <= (op - 1)->val.ival) {
                uscita = 0;
            }
        } else {
            //E' globale e io non sono nel main
            if (strcmp(table->scope, "Globale") != 0) {
                Oid = getOid(n->b->value.sval, getGlobale());
                if (((aproot)->startPoint + Oid)->val.ival <= (op - 1)->val.ival) {
                    uscita = 0;
                }
            }
        }
        diminuisciOp();

        //Runno il corpo del for se uscita = 0;
        if (!uscita) {
            bodyex(n->c2, table);
        }
        //Aumento di 1
        int prec = getValueVarStack(n->b->value.sval,table).ival;
        prec++;
        Ostackrecord os;
        os.tipo = INTE;
        os.val.ival = prec;
        *op = os;
        aumentaOp();
        cambiaValInStack(n->b->value.sval,table);
    }while(uscita!=1);
}

void ifStatex(Pnode n,Table *table){
    exprex(n->c1,table);
    int cond = (op-1)->val.bval;
    diminuisciOp();
    if(cond){
        bodyex(n->c2,table);
    }else{
        bodyex(n->c1->b,table);
    }
}

void cambiaValInStack(char *s,Table *table){
    //Controllo se la variabile e' locale
    int Oid = getOid(s, table);
    if (Oid != -1) {
        ((ap - 1)->startPoint + Oid)->val = (op - 1)->val;
        diminuisciOp();
    }
    //E' globale e io non sono nel main
    else if (strcmp(table->scope, "Globale") != 0) {
        Oid = getOid(s, getGlobale());
        ((aproot)->startPoint + Oid)->val = (op - 1)->val;
        diminuisciOp();
    }
}

void returnStatex(Pnode n, Table *table) {
    if(n->c1!=NULL){
        exprex(n->c1, table);
        (((ap-2)->startPoint)+(ap-2)->nObjs-1)->val = (op-1)->val;
        ap--;
        op = (ap-1)->startPoint+(ap-1)->nObjs;
    }
}

void funcCallex(Pnode n,Table *table){
    //Creo uno slot sullo stack per metterci il valore di ritorno (se non void)
    if (lookUp(n->c1->value.sval,getGlobale())->tipo != VOIDE){
        Ostackrecord ost;
        ost.tipo = lookUp(n->c1->value.sval,getGlobale())->tipo;
        *op = ost;
        aumentaOp();
    }

    Astack as;
    as.startPoint = op;
    as.nObjs = 0;
    *ap = as;
    ap++;
    table = lookUp(n->c1->value.sval,getGlobale())->ambiente;
    //Creo gli slot nello stack che conterranno i parametri formali
    createRA(n->c1->value.sval);
    Pnode temp = n->c1->c1;
    int i = 0;
    //Do il valore agli slot con le expr che passo in parentesi
    while (temp != NULL) {
        exprex(temp, table);
        ((ap - 1)->startPoint + i)->val = (op - 1)->val;
        diminuisciOp();
        i++;
        temp = temp->b;
    }
    //Creo sullo stack le variabili locali della funzione
    int exit = 0;
    Pnode funPointer = rootAST->c2;
    do{
        if(strcmp(funPointer->c2->value.sval,n->c1->value.sval)==0){
            exit = 1;
            if(funPointer->c1!=NULL)
                varDeclListex(funPointer->c1);
        }
        if(exit!=1) funPointer = funPointer->b;
    }while(exit!=1);
    //Eseguo il corpo della funzione chiamata, sullo stack c'e' gia tutto
    bodyex(funPointer->c2->c1, lookUp(n->c1->value.sval, getGlobale())->ambiente);
}

void exprex(Pnode n, Table *table) {
    Ostackrecord os;
    switch (n->type) {
        case T_AND:
            exprex(n->c1, table);
            booltermex(n->c2, table);
            os.tipo = BOOLE;
            if (!(op - 2)->val.bval)
                os.val.bval = FALSE;
            else
                os.val.bval = (op - 1)->val.bval;
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_OR:
            exprex(n->c1, table);
            booltermex(n->c2, table);
            os.tipo = BOOLE;
            if ((op - 2)->val.bval)
                os.val.bval = TRUE;
            else
                os.val.bval = (op - 1)->val.bval;
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            booltermex(n, table);
    }
}

void booltermex(Pnode n, Table *table) {
    Ostackrecord os;
    switch (n->type) {
        case T_EQU:
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n->c1, table);
            relTermex(n->c2, table);
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
            relTermex(n, table);
    }
}

void relTermex(Pnode n, Table *table) {
    Ostackrecord os;
    switch (n->type) {
        case T_PLUS:
            relTermex(n->c1, table);
            lowTermex(n->c2, table);
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
                relTermex(n->c1, table);
                lowTermex(n->c2, table);
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
                lowTermex(n, table);
            }
            break;
        default:
            lowTermex(n, table);
    }
}

void lowTermex(Pnode n, Table *table) {
    Ostackrecord os;
    switch (n->type) {
        case T_STAR:
            lowTermex(n->c1, table);
            factorex(n->c2, table);
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
            lowTermex(n->c1, table);
            factorex(n->c2, table);
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
            factorex(n, table);
    }
}

void factorex(Pnode n, Table *table) {
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
            os.val = n->value;
            *op = os;
            aumentaOp();
            break;
        case T_MINUS:
            factorex(n->c1, table);
            if ((op - 1)->tipo == INTE)
                (op - 1)->val.ival = -((op - 1)->val.ival);
            else
                (op - 1)->val.rval = -((op - 1)->val.rval);
            break;
        case T_NOT:
            factorex(n->c1, table);
            if ((op - 1)->val.bval == FALSE)
                (op - 1)->val.bval = TRUE;
            else
                (op - 1)->val.bval = FALSE;
            break;
        case T_NONTERMINAL:
            if (n->value.ival == NFUNC_CALL) {
                funcCallex(n,table);
            } else if (n->value.ival == NCOND_EXPR) {
                exprex(n->c1, table);
                if ((op - 1)->val.bval) {
                    diminuisciOp();
                    exprex(n->c1, table);
                } else {
                    diminuisciOp();
                    exprex(n->c2, table);
                }
            }
            break;
        case T_ID:
            if (getOid(n->value.sval, table) != -1) {
                os.tipo = lookUp(n->value.sval, table)->tipo;
                os.val = ((ap - 1)->startPoint + getOid(n->value.sval, table))->val;
                *op = os;
                aumentaOp();
            }else if (strcmp(table->scope, "Globale") != 0) {
                os.tipo = lookUp(n->value.sval, getGlobale())->tipo;
                os.val = ((aproot)->startPoint + getOid(n->value.sval, getGlobale()))->val;
                *op = os;
                aumentaOp();
            }
            break;
        case T_INTEGER:
            exprex(n->c1, table);
            (op - 1)->val.ival = (int) (op - 1)->val.rval;
            break;
        case T_REAL:
            exprex(n->c1, table);
            (op - 1)->val.rval = (op - 1)->val.ival;
            break;
        default:
            exprex(n, table);
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

int isInt(char *s){
    for(int i=0;i<strlen(s);i++){
        if(!(s[i] >= '0' && s[i] <='9'))
            return 0;
    }
    return 1;
}

int isReale(char *s){
    int almenoUno = 0,punto = 0,almenoUnoDec=0;
    for(int i=0;i<strlen(s);i++){
        if(!(s[i] >= '0' && s[i] <='9')){
            if(s[i]=='.'&&almenoUno&&!punto)
                punto = 1;
            else
                return 0;
        } else{
            if(punto)
                almenoUnoDec = 1;
            else
                almenoUno = 1;
        }
    }
    if(almenoUno&&punto&&almenoUnoDec)
        return 1;
    return 0;
}

int isBool(char *s){
    if(strcmp(s,"true")==0||strcmp(s,"false")==0)
        return 1;
    return 0;
}

Value getValueVarStack(char *s,Table *table){
    //Controllo se la variabile e' locale
    int Oid = getOid(s, table);
    if (Oid != -1) {
        return ((ap - 1)->startPoint + Oid)->val;
    }
        //E' globale e io non sono nel main
    else if (strcmp(table->scope, "Globale") != 0) {
        Oid = getOid(s, getGlobale());
        return ((aproot)->startPoint + Oid)->val;
    }
}

void errRunTime(){
    exit(-1);
}