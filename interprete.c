#include "interprete.h"
#include "string.h"
extern Ostackrecord *op;
extern Astack *ap,*aproot;
Pnode rootAST;

void runCode(Pnode root){
    initRunStructure();

    rootAST = root;

    if(root->c1!=NULL)
        varDeclListex(root->c1,0);

    bodyex(root->b,getGlobale());

    printAStack();
}

void varDeclListex(Pnode n, int nVars){
    HashType tipo;
    tipo = getHashTypeN(n->c2,0);

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
        nVars++;
        *op = otemp;
        op++;
        temp = temp->b;
    }
    if(n->b != NULL) varDeclListex(n->b,nVars);
    else{
        Astack atemp;
        atemp.nObjs = nVars;
        atemp.startPoint = op-nVars;
        *ap = atemp;
        ap++;
    }
}

void createRA(char *funName){
    Entry *e = lookUp(funName,getGlobale());
    for(int i=0;i<e->nformali;i++){
        Ostackrecord os;
        os.tipo = e->dformali[i]->tipo;
        *op = os;
        aumentaOp();
    }
}

void bodyex(Pnode n,Table *table){
    while (n != NULL) {
        switch (n->value.ival) {
            case NASSIGN_STAT:
                assignStatex(n,table);
                break;
        }
        n = n->b;
    }
}

void assignStatex(Pnode n,Table *table){
    exprex(n->c2,table);
    //Controllo se la variabile e' locale
    int Oid = getOid(n->c1->value.sval,table);
    if(Oid!=-1){
        ((ap-1)->startPoint+Oid)->val = (op-1)->val;
        diminuisciOp();
    }
    //E' globale e io non sono nel main
    if(strcmp(table->scope,"Globale")!=0){
        Oid = getOid(n->c1->value.sval,getGlobale());
        ((aproot)->startPoint+Oid)->val = (op-1)->val;
    }
}

void exprex(Pnode n, Table *table){
    Ostackrecord os;
    switch (n->type) {
        case T_AND:
            exprex(n->c1,table);
            booltermex(n->c2,table);
            os.tipo = BOOLE;
            if(!(op-2)->val.bval)
                os.val.bval = FALSE;
            else
                os.val.bval = (op-1)->val.bval;
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_OR:
            exprex(n->c1,table);
            booltermex(n->c2,table);
            os.tipo = BOOLE;
            if((op-2)->val.bval)
                os.val.bval = TRUE;
            else
                os.val.bval = (op-1)->val.bval;
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            booltermex(n,table);
    }
}

void booltermex(Pnode n, Table *table){
    Ostackrecord os;
    switch (n->type) {
        case T_EQU:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            //Forse c'e' un modo meno lungo
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival==(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval==(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval==(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval==(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_NEQ:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival!=(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval!=(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval!=(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval!=(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_GRT:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival>(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval>(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval>(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval>(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_GEQ:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival>=(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval>=(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval>=(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval>=(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_LSS:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival<(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval<(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval<(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval<(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_LEQ:
            relTermex(n->c1,table);
            relTermex(n->c2,table);
            os.tipo = BOOLE;
            switch ((op-2)->tipo) {
                case INTE:
                    os.val.bval = (op-2)->val.ival<=(op-1)->val.ival;
                    break;
                case REALE:
                    os.val.bval = (op-2)->val.rval<=(op-1)->val.rval;
                    break;
                case STRINGE:
                    os.val.bval = (op-2)->val.sval<=(op-1)->val.sval;
                    break;
                case BOOLE:
                    os.val.bval = (op-2)->val.bval<=(op-1)->val.bval;
                    break;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            relTermex(n,table);
    }
}

void relTermex(Pnode n, Table *table){
    Ostackrecord os;
    switch (n->type) {
        case T_PLUS:
            relTermex(n->c1,table);
            lowTermex(n->c2,table);
            if((op-2)->tipo==INTE){
                os.tipo = INTE;
                os.val.ival = (op-2)->val.ival+(op-1)->val.ival;
            } else{
                os.tipo = REALE;
                os.val.rval = (op-2)->val.rval+(op-1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_MINUS:
            if(n->c2!=NULL){
                relTermex(n->c1,table);
                lowTermex(n->c2,table);
                if((op-2)->tipo==INTE){
                    os.tipo = INTE;
                    os.val.ival = (op-2)->val.ival-(op-1)->val.ival;
                } else{
                    os.tipo = REALE;
                    os.val.rval = (op-2)->val.rval-(op-1)->val.rval;
                }
                diminuisciOp();
                diminuisciOp();
                *op = os;
                aumentaOp();
            } else{
                lowTermex(n,table);
            }
            break;
        default:
            lowTermex(n,table);
    }
}

void lowTermex(Pnode n, Table *table){
    Ostackrecord os;
    switch (n->type) {
        case T_STAR:
            lowTermex(n->c1,table);
            factorex(n->c2,table);
            if((op-2)->tipo==INTE){
                os.tipo = INTE;
                os.val.ival = (op-2)->val.ival*(op-1)->val.ival;
            } else{
                os.tipo = REALE;
                os.val.rval = (op-2)->val.rval*(op-1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        case T_DIV:
            lowTermex(n->c1,table);
            factorex(n->c2,table);
            if((op-2)->tipo==INTE){
                os.tipo = INTE;
                os.val.ival = (op-2)->val.ival/(op-1)->val.ival;
            } else{
                os.tipo = REALE;
                os.val.rval = (op-2)->val.rval/(op-1)->val.rval;
            }
            diminuisciOp();
            diminuisciOp();
            *op = os;
            aumentaOp();
            break;
        default:
            factorex(n,table);
    }
}

void factorex(Pnode n, Table *table){
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
            factorex(n->c1,table);
            if((op-1)->tipo==INTE)
                (op-1)->val.ival = -((op-1)->val.ival);
            else
                (op-1)->val.rval = -((op-1)->val.rval);
            break;
        case T_NOT:
            factorex(n->c1,table);
            if((op-1)->val.bval==FALSE)
                (op-1)->val.bval = TRUE;
            else
                (op-1)->val.bval = FALSE;
            break;
        case T_NONTERMINAL:
            if(n->value.ival==NFUNC_CALL){
                //todo
                Astack as;
                as.startPoint=op;
                as.nObjs = 0;
                *ap = as;
                ap++;
                createRA(n->c1->value.sval);
                Pnode temp = n->c1->c1;
                int i=0;
                while(temp != NULL){
                    exprex(temp,table);
                    ((ap-1)->startPoint+i)->val=(op-1)->val;
                    diminuisciOp();
                    i++;
                    temp = temp->b;
                }
            }
            else if(n->value.ival==NCOND_EXPR){
                exprex(n->c1,table);
                if((op-1)->val.bval) {
                    diminuisciOp();
                    exprex(n->c1, table);
                }
                else {
                    diminuisciOp();
                    exprex(n->c2, table);
                }
            }
            break;
        case T_ID:
            if(getOid(n->value.sval,table)!=-1){
                os.tipo = lookUp(n->value.sval,table)->tipo;
                os.val = ((ap-1)->startPoint+getOid(n->value.sval,table))->val;
                *op = os;
                aumentaOp();
            }
            else{
                //todo
            }
            break;
        case T_INTEGER:
            exprex(n->c1,table);
            (op-1)->val.ival = (int)(op-1)->val.rval;
            break;
        case T_REAL:
            exprex(n->c1,table);
            (op-1)->val.rval = (op-1)->val.ival;
            break;
        default:
            exprex(n,table);
            break;
    }
}

void aumentaOp(){
    op++;
    (ap-1)->nObjs++;
}

void diminuisciOp(){
    op--;
    (ap-1)->nObjs--;
}