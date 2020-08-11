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
HashType expr(Pnode n);
HashType boolterm(Pnode n);
HashType relTerm(Pnode n);
HashType lowTerm(Pnode n);
HashType factor(Pnode n);
#endif //PROVATECNOLOGIE_SEMANTICA_H
