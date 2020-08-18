#include "runStructure.h"
#define MAX_STACK 256

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
        printf("%s | %d",tipiToStringr[ostackr->tipo],ostackr->val.ival);
        printf(" ]\n");
    }
    printf("----------------ASTACK------------------\n");
    for(Astack *astackr = astack;astackr<ap;astackr++){
        printf("[ ");
        printf("%d | %d",astackr->nObjs,astackr->startPoint->val.ival);
        printf(" ]\n");
    }
}
