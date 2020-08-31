//
// Created by marco on 16/08/2020.
//

#ifndef PROVATECNOLOGIE_INTERPRETE_H
#define PROVATECNOLOGIE_INTERPRETE_H
#include "def.h"
#include "table.h"
#include "semantica.h"
#include "runStructure.h"
#include "stringPoolStructure.h"
#include "heap.h"
void runCode(Pnode root);
void varDeclListex(Pnode n);
void bodyex(Pnode n);
void assignStatex(Pnode n);
void ifStatex(Pnode n);
void forStatex(Pnode n);
void returnStatex(Pnode n);
void readStatex(Pnode n);
void writeStatex(Pnode n);
void funcCallex(Pnode n);
void exprex(Pnode n);
void booltermex(Pnode n);
void relTermex(Pnode n);
void lowTermex(Pnode n);
void factorex(Pnode n);
void aumentaOp();
void diminuisciOp();
void createRA(char *funName);
void breakStatex(Pnode n);
void whileStatex(Pnode n);
void cambiaValInStack(char *s);
void errRunTime();
int isInt(char *s);
int isReale(char *s);
int isBool(char *s);
Value getValueVarStack(char *s);
#endif //PROVATECNOLOGIE_INTERPRETE_H
