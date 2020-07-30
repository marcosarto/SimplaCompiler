#ifndef PROVATECNOLOGIE_TABLE_H
#define PROVATECNOLOGIE_TABLE_H
#define TOT 5
#define SHIFT 4
#include "def.h"

typedef struct stable Table;
typedef struct sentry Entry;

struct sentry{
    char* key;
    enum {VAR, PAR, FUN} classe;
    int oid;
    enum {INTE, REALE, STRINGE, BOOLE, VOIDE} tipo;
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
void insert (Entry *entry);
void initTable();
void print();

#endif //PROVATECNOLOGIE_TABLE_H
