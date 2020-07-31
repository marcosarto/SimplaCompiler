#ifndef PROVATECNOLOGIE_TABLE_H
#define PROVATECNOLOGIE_TABLE_H
#define TOT 1013
#define SHIFT 4
#include "def.h"

typedef struct stable Table;
typedef struct sentry Entry;
typedef enum{
    VAR,
    PAR,
    FUN
}Classi;
typedef enum{
    INTE,
    REALE,
    STRINGE,
    BOOLE,
    VOIDE
}HashType;


struct sentry{
    char* key;
    Classi classe;
    int oid;
    HashType tipo;
    Table* ambiente;
    int nformali;
    Entry* dformali[TOT];
    Entry* next;
};

struct stable{
    int count;
    int capacity;
    Entry* entry[TOT];
};

int hash(char* id);
int insert (Entry *entry);
int insertInto(Entry *entry,Table *tableP);
void initTable();
void print(Table *table);
Table* creaAmbiente();
Table* getGlobale();

#endif //PROVATECNOLOGIE_TABLE_H
