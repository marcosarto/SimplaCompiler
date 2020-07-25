%{   
#include "parser.h"                                             
#include "def.h"
int line = 1;                                                   
Value lexval;
%}                                                              
%option noyywrap
spacing     ([ \t])+
letter      [A-Za­z]
digit       [0­9]
intconst    {digit}+
realconst   {digit}+\.{digit}+
strconst    \"([^\"])*\"
boolconst   false|true
id          {letter}({letter}|{digit})*
sugar       [(){}:;,]
comment     #.*\n
%%
{spacing}   ;
\n          {line++;}
{comment}   ;
integer     {return(INTEGER);}
real        {return(REAL);}
string      {return(STRING);}
boolean     {return(BOOLEAN);}
func        {return(FUNC);}
body        {return(BODY);}
if          {return(IF);}
else        {return(ELSE);}
then        {return(THEN);}
end         {return(END);}
return      {return(RETURN);}
void        {return(VOID);}
for         {return(FOR);}
to          {return(TO);}
do          {return(DO);}
writeln     {return(WRITELN);}
write       {return(WRITE);}
read        {return(READ);}
while       {return(WHILE);}
break       {return(BREAK);}
"+"         {return(PLUS);}
"-"         {return(MINUS);}
"*"         {return(STAR);}
"/"         {return(DIVIDE);}
and         {return(AND);}
or          {return(OR);}
not         {return(NOT);}
"="         {return(EQUAL);}
"=="        {return(EQUALS);}
"!="        {return(NOTEQUALS);}
">"         {return(GRTHAN);}
"<"         {return(LSTHAN);}
">="        {return(GRETHAN);}
"<="        {return(LSETHAN);}
{intconst}  {lexval.ival = atoi(yytext); return(INTCONST);}
{realconst} {lexval.rval = atof(yytext); return(REALCONST);}
{strconst}  {lexval.sval = newstring(yytext); return(STRCONST);}
{boolconst} {lexval.bval = (yytext[0] == 'f' ? FALSE : TRUE); return(BOOLCONST);}
{id}        {lexval.sval = newstring(yytext); return(ID);}
{sugar}     {return(yytext[0]);}
.           {return(ERROR);}
%%
char *newstring(char *s)
{
  char *p;
  
  p = malloc(strlen(s)+1);
  strcpy(p, s);
  return(p);
}
