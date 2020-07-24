%{
#include "def.h"
#define YYSTYPE Pnode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
Pnode root = NULL;
%}
%token INTEGER REAL STRING BOOLEAN VOID ID FUNC BODY END BREAK
%token EQU NEQ GEQ LEQ AND OR IF ELSE INTCONST NOT REALCONST
%token STRCONST THEN BOOLCONST DO FOR READ RETURN TO WHILE
%token WRITE WRITELN
%start program 
%%
program : var_decl_list func_decl_list body '.' {$$ = nontermnode(NPROGRAM);
                                                $$->c1 = $1;
                                                $$->c2 = $2;
                                                $$->b = $3;}
        ;
var_decl_list : var_decl var_decl_list {$$ = $1; $1->b = $2;}
            | {$$ = NULL;}
            ;
var_decl : id_list ':' type ';' {$$ = nontermnode(NVAR_DECL);
                                $$->c1 = $1;
                                $$->c2 = $3;}
        ;
id_list : ID {$$ = idnode();} ',' id_list {$$ = $2; $2->b = $3;}
        | ID {$$ = idnode();}
        ;
type : INTEGER {$$ = keynode(T_INTEGER);}
    | REAL {$$ = keynode(T_REAL);}
    | STRING {$$ = keynode(T_STRING);}
    | BOOLEAN {$$ = keynode(T_BOOLEAN);}
    | VOID {$$ = keynode(T_VOID);}
    ;
func_decl_list : func_decl func_decl_list {$$ = $1; $1->b = $2;}
        | {$$ = NULL;}
        ;
func_decl : FUNC ID {$$ = idnode();} '(' opt_param_list ')' ':' type var_decl_list body ';' {$$ = nontermnode(NFUNC_DECL);
                                                                                        $$->c1 = $9;
                                                                                        $$->c2 = $10;
                                                                                        $$->b = $3;
                                                                                        $3->b = $8;
                                                                                        $8->b = $5;}
        ;
opt_param_list : param_list {$$ = nontermnode(NOPT_PARAM_LIST);
                        $$->c1 = $1;}
        | {$$ = NULL;}
        ;
param_list : param_decl ',' param_list {$$ = $1; $1->b = $3;}
        | param_decl
        ;
param_decl : ID {$$ = idnode();} ':' type {$$ = nontermnode(NPARAM_DECL);
                                        $$->c1 = $2;
                                        $$->c2 = $4;}
body : BODY stat_list END {$$ = $2;}
;
stat_list : stat ';' stat_list {$$ = $1; $1->b = $3;}
        | stat ';' {$$ = $1;}
        ;
stat : assign_stat
| if_stat
| while_stat
| for_stat
| return_stat
| read_stat
| write_stat
| func_call
| BREAK {$$ = keynode(T_BREAK);}
;
assign_stat : ID {$$ = idnode();} '=' expr {$$ = nontermnode(NASSIGN_STAT);
                                        $$->c1 = $2;
                                        $$->c2 = $4;}
        ;
if_stat : IF expr THEN stat_list opt_else_stat END {$$ = nontermnode(NIF_STAT);
                                                $$->c1 = $2;
                                                $$->c2 = $4;
                                                $$->b = $5;}
        ;
opt_else_stat : ELSE stat_list {$$ = $2;}
        | {$$ = NULL;}
        ;
while_stat : WHILE expr DO stat_list END {$$ = nontermnode(NWHILE_STAT);
                                        $$->c1 = $2;
                                        $$->c2 = $4;}
        ;
for_stat : FOR ID {$$ = idnode();} '=' expr TO expr DO stat_list END{$$ = nontermnode(NFOR_STAT);
                                                                $$->c1 = $6;
                                                                $$->c2 = $8;
                                                                $$->b = $3;
                                                                $3->b = $5;}
        ;
return_stat : RETURN opt_expr {$$ = nontermnode(NRETURN_STAT);
                        $$->c1 = $2;}
        ;
opt_expr : expr
        | {$$ = NULL;}
        ;
read_stat : READ '(' id_list ')' {$$ = nontermnode(NREAD_STAT);
                                $$->c1 = $3;}
        ;
write_stat : write_op '(' expr_list ')' {$$ = nontermnode(NWRITE_STAT);
                                        $$->c1 = $1;
                                        $$->c2 = $3;}
        ;
write_op : WRITE {$$ = keynode(T_WRITE);}
        | WRITELN {$$ = keynode(T_WRITELN);}
        ;
expr : expr logic_op bool_term {$$->c1 = $1;
                                $$->c2 = $2;
                                $$->b = $3;}
| bool_term {$$->c1 = $1;}
;
logic_op : AND {$$ = keynode(T_AND);}
        | OR {$$ = keynode(T_OR);}
        ;
bool_term : rel_term rel_op rel_term {$$->c1 = $1;
                                $$->c2 = $2;
                                $$->b = $3;}
        | rel_term {$$->c1 = $1;}
        ;
rel_op : EQU {$$ = keynode(T_EQU);}
| NEQ {$$ = keynode(T_NEQ);}
| '>' {$$ = keynode(T_GRT);}
| GEQ {$$ = keynode(T_GEQ);}
| '<' {$$ = keynode(T_LSS);}
| LEQ {$$ = keynode(T_LEQ);}
;
rel_term : rel_term low_prec_op low_term {$$->c1 = $1;
                                        $$->c2 = $2;
                                        $$->b = $3;}
        | low_term {$$->c1 = $1;}
        ;
low_prec_op : '+' {$$ = keynode(T_PLUS);}
        | '-' {$$ = keynode(T_MINUS);}
        ;
low_term : low_term high_prec_op factor {$$->c1 = $1;
                                        $$->c2 = $2;
                                        $$->b = $3;}
        | factor {$$->c1 = $1;}
        ;
high_prec_op : '*' {$$ = keynode(T_STAR);}
        | '/' {$$ = keynode(T_DIV);}
        ;
factor : unary_op factor {$$->c1 = $1;
                        $$->c2 = $2;}
| '(' expr ')' {$$->c1 = $2;}
| ID {$$ = idnode();} {$$->c1 = $2;}
| const {$$->c1 = $1;}
| func_call {$$->c1 = $1;}
| cond_expr {$$->c1 = $1;}
| cast '(' expr ')' {$$->c1 = $1;
                $$->c2 = $3;}
;
unary_op : '-' {$$ = keynode(T_MINUS);}
        | NOT {$$ = keynode(T_NOT);}
        ;
const : INTCONST {$$ = intconstnode();}
| REALCONST {$$ = realconstnode();}
| STRCONST {$$ = strconstnode();}
| BOOLCONST {$$ = boolconstnode();}
;
func_call : ID {$$ = idnode();} '(' opt_expr_list ')' {$$->c1 = $2;
                                                        $$->c2 = $4;}
        ;
opt_expr_list : expr_list
        | {$$ = NULL;}
        ;
expr_list : expr ',' expr_list {$$ = $1; $1->b = $3;}
        | expr
        ;
cond_expr : IF expr THEN expr ELSE expr END {$$->c1 = $2;
                                        $$->c2 = $4;
                                        $$->b = $6;}
        ;
cast : INTEGER {$$ = keynode(T_INTEGER);}
| REAL {$$ = keynode(T_REAL);}
;
%%
