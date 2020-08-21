#ifndef PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
#define PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
#define TOTR 1013
#define SHIFTR 4
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stringHeap.h"
#include "writeToFile.h"

typedef struct sentryr Entryr;

struct sentryr{
    char* key;
    Entryr* next;
};

typedef struct stabler{
    Entryr* entry[TOTR];
}Tabler;

void initStringPool();
char* addString(char *e);
void printStringPoolStructure();
char* addStringLiteral(char *e);
#endif //PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
