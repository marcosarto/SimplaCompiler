#include "runStructure.h"
#define MAX_STACK 1024

Ostackrecord ostack[MAX_STACK];
Astack astack[MAX_STACK];
Ostackrecord *op;
Astack *ap,*aproot;


char* tipiToStringr[] =
        {
                "INTEGER",
                "REAL",
                "STRING",
                "BOOLEAN",
                "VOID"
        };


void initRunStructure(){
    ap = aproot = astack;
    op = ostack;
}


void printAStack(){
    printf("----------------OSTACK------------------\n");
    for(Ostackrecord *ostackr = ostack;ostackr<op;ostackr++){
        printf("[ ");
        switch (ostackr->tipo) {
            case BOOLE:
            case INTE:
                printf("%s | %d",tipiToStringr[ostackr->tipo],ostackr->val.ival);
                break;
            case REALE:
                printf("%s | %f",tipiToStringr[ostackr->tipo],ostackr->val.rval);
                break;
            case STRINGE:
                printf("%s | %s",tipiToStringr[ostackr->tipo],ostackr->val.sval);
                break;
        }
        printf(" ]\n");
    }
    printf("----------------ASTACK------------------\n");
    for(Astack *astackr = astack;astackr<ap;astackr++){
        printf("[ ");
        printf("%d | %d",astackr->nObjs,astackr->startPoint->val.ival);
        printf(" ]\n");
    }
}
