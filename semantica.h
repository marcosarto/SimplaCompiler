#ifndef PROVATECNOLOGIE_SEMANTICA_H
#define PROVATECNOLOGIE_SEMANTICA_H
#include "def.h"
#include "table.h"

void evalType(Pnode n);
void varDeclList(Pnode n);
void funDeclList(Pnode n);
HashType getHashTypeN(Pnode n,int ancheFunzioni);
void varDeclListInterno(Pnode n,Table *table);
#endif //PROVATECNOLOGIE_SEMANTICA_H
