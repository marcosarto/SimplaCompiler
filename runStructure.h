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
    Table *table;
}Astack ;

void initRunStructure();
void printAStack();
void printAStackstout();

#endif //PROVATECNOLOGIE_RUNSTRUCTURE_H
