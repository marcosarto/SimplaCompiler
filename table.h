#ifndef PROVATECNOLOGIE_TABLE_H
#define PROVATECNOLOGIE_TABLE_H
#define TOT 1013
#define SHIFT 4
#include "def.h"
#include "writeToFile.h"
typedef struct stable Table;
typedef struct sentry Entry;
typedef enum hashtypeenum HashType;

typedef enum{
    VAR,
    PAR,
    FUN
}Classi;

enum hashtypeenum{
    INTE,
    REALE,
    STRINGE,
    BOOLE,
    VOIDE,
};

struct sentry{
    char* key;
    Classi classe;
    int oid;
    int pointer;
    int nstars;
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
Entry *lookUpCond(char *s,Table *tableP,int checkStars);
int getOidP(char *s, Table *tableP);
Entry* lookUp(char *s,Table *tableP);
void print(Table *table);
Table* creaAmbiente();
Table* getGlobale();
int getOid(char *s,Table *tableP);

#endif //PROVATECNOLOGIE_TABLE_H
