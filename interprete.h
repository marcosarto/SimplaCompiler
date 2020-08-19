//
// Created by marco on 16/08/2020.
//

#ifndef PROVATECNOLOGIE_INTERPRETE_H
#define PROVATECNOLOGIE_INTERPRETE_H
#include "def.h"
#include "table.h"
#include "semantica.h"
#include "runStructure.h"
void runCode(Pnode root);
void varDeclListex(Pnode n);
void bodyex(Pnode n,Table *table);
void assignStatex(Pnode n,Table *table);
void ifStatex(Pnode n,Table *table);
void forStatex(Pnode n,Table *table);
void returnStatex(Pnode n,Table *table);
void readStatex(Pnode n,Table *table);
void writeStatex(Pnode n,Table *table);
void funcCallex(Pnode n,Table *table);
void exprex(Pnode n, Table *table);
void booltermex(Pnode n, Table *table);
void relTermex(Pnode n, Table *table);
void lowTermex(Pnode n, Table *table);
void factorex(Pnode n, Table *table);
void aumentaOp();
void diminuisciOp();
void createRA(char *funName);
void cambiaValInStack(char *s,Table *table);
void errRunTime();
int isInt(char *s);
int isReale(char *s);
int isBool(char *s);
Value getValueVarStack(char *s,Table *table);
#endif //PROVATECNOLOGIE_INTERPRETE_H
