#include "runStructure.h"
#define MAX_STACK 1024

Ostackrecord ostack[MAX_STACK];
Astack astack[MAX_STACK];
Ostackrecord *op,*oproot;
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
    op = oproot = ostack;
}
void printAStackstout(){
    printf("--------------OSTACK(TIPO|VAL)--------------\n");
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
    printf("--------ASTACK(nOggetti|Val del primo)--------\n");
    for(Astack *astackr = astack;astackr<ap;astackr++){
        printf("[ ");
        printf("%d | %d",astackr->nObjs,astackr->startPoint->val.ival);
        printf(" ]\n");
    }
    printf("\n\n");
}

void printAStack(){
    char *toWrite = malloc(sizeof(char)*200);
    writeToFile("--------------OSTACK(TIPO|VAL)--------------\n");
    for(Ostackrecord *ostackr = ostack;ostackr<op;ostackr++){
        writeToFile("[ ");
        switch (ostackr->tipo) {
            case BOOLE:
            case INTE:
                sprintf(toWrite,"%s | %d",tipiToStringr[ostackr->tipo],ostackr->val.ival);
                writeToFile(toWrite);
                break;
            case REALE:
                sprintf(toWrite,"%s | %f",tipiToStringr[ostackr->tipo],ostackr->val.rval);
                writeToFile(toWrite);
                break;
            case STRINGE:
                sprintf(toWrite,"%s | %s",tipiToStringr[ostackr->tipo],ostackr->val.sval);
                writeToFile(toWrite);
                break;
        }
        writeToFile(" ]\n");
    }
    writeToFile("--------ASTACK(nOggetti|Val del primo)--------\n");
    for(Astack *astackr = astack;astackr<ap;astackr++){
        writeToFile("[ ");
        sprintf(toWrite,"%d | %d",astackr->nObjs,astackr->startPoint->val.ival);
        writeToFile(toWrite);
        writeToFile(" ]\n");
    }
    writeToFile("\n\n");
}
