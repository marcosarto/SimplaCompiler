%{
#include "def.h"
#include "table.h"
#include "semantica.h"
#include "interprete.h"
#include "writeToFile.h"
#define YYSTYPE Pnode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
Pnode root = NULL;
%}
%token INTEGER REAL STRING BOOLEAN VOID ID FUNC BODY END BREAK
%token EQU NEQ GEQ LEQ AND OR IF ELSE INTCONST NOT REALCONST
%token STRCONST THEN BOOLCONST DO FOR READ RETURN TO WHILE GRT LSS
%token WRITE WRITELN PLUS STAR MINUS EQUAL DIV ADDR NEW PRINTSTACK
%start program 
%%
program : var_decl_list func_decl_list body '.' {root = $$ = nontermnode(NPROGRAM);
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
id_list : ID {$$ = idnode();} ',' id_list {$$ = $2; $2->b = $4;}
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
                                                                                        $$->c2 = $3;
                                                                                        $3->c1 = $10;
                                                                                        $3->c2 = $5;
                                                                                        $3->b = $8;}
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
           ;
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
| print_stack
| BREAK {$$ = keynode(T_BREAK);}
;
assign_stat : ID {$$ = idnode();} EQUAL expr {$$ = nontermnode(NASSIGN_STAT);
                                                    $$->c1 = $2;
                                                    $$->c2 = $4;}
        ;
if_stat : IF expr THEN stat_list opt_else_stat END {$$ = nontermnode(NIF_STAT);
                                                $$->c1 = $2;
                                                $$->c2 = $4;
                                                $2->b = $5;}
        ;
opt_else_stat : ELSE stat_list {$$ = $2;}
        | {$$ = NULL;}
        ;
print_stack : PRINTSTACK '(' ')' {$$ = nontermnode(NPRINT_STACK);}
            ;
while_stat : WHILE expr DO stat_list END {$$ = nontermnode(NWHILE_STAT);
                                        $$->c1 = $2;
                                        $$->c2 = $4;}
        ;
for_stat : FOR ID {$$ = idnode();} EQUAL expr TO expr DO stat_list END{$$ = nontermnode(NFOR_STAT);
                                                                $$->c1 = $3;
                                                                $$->c2 = $9;
                                                                $3->c1 = $5;
                                                                $3->c2 = $7;}
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
expr_list : expr ',' expr_list {$$ = $1; $1->b = $3;}
        | expr
        ;
expr : expr logic_op bool_term {$$= $2;
                                $2->c1 = $1;
                                $2->c2 = $3;
                                }
    | bool_term {$$ = $1;}
    ;
logic_op : AND {$$ = keynode(T_AND);}
        | OR {$$ = keynode(T_OR);}
        ;
bool_term : rel_term rel_op rel_term {$$=$2;
                                        $2->c1=$1;
                                        $2->c2=$3;
                                        }
        | rel_term {$$ = $1;}
        ;
rel_op : EQU {$$ = keynode(T_EQU);}
| NEQ {$$ = keynode(T_NEQ);}
| GRT {$$ = keynode(T_GRT);}
| GEQ {$$ = keynode(T_GEQ);}
| LSS {$$ = keynode(T_LSS);}
| LEQ {$$ = keynode(T_LEQ);}
;
rel_term : rel_term low_prec_op low_term {$$ = $2;
                                        $2->c1 = $1;
                                        $2->c2 = $3;}
        | low_term {$$ = $1;}
        ;
low_prec_op : PLUS {$$ = keynode(T_PLUS);}
        | MINUS {$$ = keynode(T_MINUS);}
        ;
low_term : low_term high_prec_op factor {$$ = $2;
                                        $2->c1 = $1;
                                        $2->c2 = $3;}
        | factor {$$ = $1;}
        ;
high_prec_op : STAR {$$ = keynode(T_STAR);}
        | DIV {$$ = keynode(T_DIV);}
        ;
factor : unary_op factor {$$ = $1;
                        $$->c1 = $2;}
| '(' expr ')' {$$ = $2;}
| ID {$$ = idnode();}
| ADDR ID {$$ = idnode();} {$$ = keynode(T_ADDR);
                            $$->c1 = $3;}
| const {$$ = $1;}
| func_call
| cond_expr
| cast '(' expr ')' {$$ = $1;
                $1->c1 = $3;}
;
unary_op : MINUS {$$ = keynode(T_MINUS);}
        | NOT {$$ = keynode(T_NOT);}
        ;
const : INTCONST {$$ = intconstnode();}
| REALCONST {$$ = realconstnode();}
| STRCONST {$$ = strconstnode();}
| BOOLCONST {$$ = boolconstnode();}
;
func_call : ID {$$ = idnode();} '(' opt_expr_list ')' {$$ = nontermnode(NFUNC_CALL);
                                                       $$->c1 = $2;
                                                       $2->c1 = $4;}
        ;
opt_expr_list : expr_list
        | {$$ = NULL;}
        ;
cond_expr : IF expr THEN expr ELSE expr END {$$ = nontermnode(NCOND_EXPR);
                                        $$->b = $2;
                                        $$->c1 = $4;
                                        $$->c2 = $6;}
        ;
cast : INTEGER {$$ = keynode(T_INTEGER);}
| REAL {$$ = keynode(T_REAL);}
;
%%
Pnode nontermnode(Nonterminal nonterm)
{
    Pnode p = newnode(T_NONTERMINAL);
    p->value.ival = nonterm;
    return(p);
}
Pnode idnode()
{
    Pnode p = newnode(T_ID);
    p->value.sval = lexval.sval;
    return(p);
}
Pnode keynode(Typenode keyword)
{
    return(newnode(keyword));
}
Pnode intconstnode()
{
    Pnode p = newnode(T_INTCONST);
    p->value.ival = lexval.ival;
    return(p);
}
Pnode strconstnode()
{
    Pnode p = newnode(T_STRCONST);
    p->value.sval = lexval.sval;
    return(p);
}
Pnode realconstnode()
{
    Pnode p = newnode(T_REALCONST);
    p->value.rval = lexval.rval;
    return(p);
}
Pnode boolconstnode()
{
  Pnode p = newnode(T_BOOLCONST);
  p->value.bval = lexval.bval;
  return(p);
}
Pnode newnode(Typenode tnode)
{
  Pnode p = malloc(sizeof(Node));
  p->type = tnode;
  p->linen = line;
  p->c1 = p->c2 = p->b = NULL;
  return(p);
}
int main(int argc, char **argv)
{
    int result;
    initTable();
    initWriteToFile();

    if(argc!=2) {
            printf("Inserisci un solo argomento\n");
            exit(-5);
        }

    yyin = fopen(argv[1], "r");

    if((result = yyparse()) == 0){
        //treeprint(root,0);
        Pnode semCheckRoot = root;
        evalType(semCheckRoot);
        print(getGlobale());
        runCode(root);
        closeWriteToFile();
        }
    return(result);
}


int yywrap()
{
        return 1;
}

void yyerror()
{
  fprintf(stderr, "Line %d: errSintattico del simbolo \"%s\"\n",
          line, yytext);
  exit(-1);
}
