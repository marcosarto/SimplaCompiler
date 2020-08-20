#ifndef PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
#define PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
#define TOTR 1013
#define SHIFTR 4
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stringHeap.h"

typedef struct sentry Entryr;

struct sentry{
    char* key;
    Entryr* next;
};

typedef struct stable{
    Entryr* entry[TOTR];
}Tabler;

void initStringPool();
char* addString(char *e);
#endif //PROVATECNOLOGIE_STRINGPOOLSTRUCTURE_H
