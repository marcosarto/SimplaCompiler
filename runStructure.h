#ifndef PROVATECNOLOGIE_RUNSTRUCTURE_H
#define PROVATECNOLOGIE_RUNSTRUCTURE_H
#include "def.h"
#include "table.h"
typedef struct {
    HashType tipo;
    Value val;
}Ostackrecord;

typedef struct Astacks{
    int nObjs;
    Ostackrecord *startPoint;
}Astack ;

void initRunStructure();
void printAStack();

#endif //PROVATECNOLOGIE_RUNSTRUCTURE_H
