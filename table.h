#ifndef PROVATECNOLOGIE_TABLE_H
#define PROVATECNOLOGIE_TABLE_H
#define TOT 1013
#define SHIFT 4
#include "def.h"
#include "writeToFile.h"
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
    int pointer;
    HashType tipo;
    Table* ambiente;
    int nformali;
    Entry* dformali[TOT];
    Entry* next;
};

struct stable{
    char *scope;
    int count;
    Entry* entry[TOT];
};

void assignScopeName(char *nome, Table *tableP);
int hash(char* id);
int insert (Entry *entry);
int insertInto(Entry *entry,Table *tableP);
void initTable();
Entry* lookUp(char *s,Table *tableP);
void print(Table *table);
Table* creaAmbiente();
Table* getGlobale();
int getOid(char *s,Table *tableP);

#endif //PROVATECNOLOGIE_TABLE_H
