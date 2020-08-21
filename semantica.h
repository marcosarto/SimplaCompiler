#ifndef PROVATECNOLOGIE_SEMANTICA_H
#define PROVATECNOLOGIE_SEMANTICA_H
#include "def.h"
#include "table.h"

void evalType(Pnode n);
void varDeclList(Pnode n);
void funDeclList(Pnode n);
HashType getHashTypeN(Pnode n,int ancheFunzioni);
void varDeclListInterno(Pnode n,Table *table);
void body(Pnode n,Table *table);
void assignStat(Pnode n, Table *table);
HashType expr(Pnode n,Table *table);
HashType boolterm(Pnode n,Table *table);
HashType relTerm(Pnode n,Table *table);
HashType lowTerm(Pnode n,Table *table);
HashType factor(Pnode n,Table *table);
void ifStat(Pnode n, Table *table);
void whileStat(Pnode n, Table *table);
void forStat(Pnode n, Table *table);
void returnStat(Pnode n, Table *table);
void readStat(Pnode n, Table *table);
HashType funcCall(Pnode n,Table *table);
void errSemantico(char *s,Pnode n);
void breakStat(Pnode n,Table *table);
#endif //PROVATECNOLOGIE_SEMANTICA_H
