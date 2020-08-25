%{   
#include "parser.h"                                             
#include "def.h"
int line = 1;                                                   
Value lexval;
%}                                                              
%option noyywrap
delimiter	[ \t]
acapo		[\r\n]{2,}
spacing		{delimiter}+
letter		[A-Za-z]
digit		[0-9]
intconst	{digit}+
realconst	{digit}+\.{digit}+
strconst	\"([^\"])*\"
boolconst	false|true
id		{letter}({letter}|{digit})*
sugar		[(){}:;,'.']
comment		#.*\n
%%
{spacing}   ;
[ \t\r\n]   ;
{acapo}     {line++;}
{comment}   {printf("riconosciuto commento");}
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
"/"         {return(DIV);}
and         {return(AND);}
or          {return(OR);}
not         {return(NOT);}
"="         {return(EQUAL);}
"=="        {return(EQU);}
"!="        {return(NEQ);}
">"         {return(GRT);}
"<"         {return(LSS);}
">="        {return(GEQ);}
"<="        {return(LEQ);}
{intconst}  {lexval.ival = atoi(yytext); return(INTCONST);}
{realconst} {lexval.rval = atof(yytext); return(REALCONST);}
{strconst}  {lexval.sval = newstring(yytext); return(STRCONST);}
{boolconst} {lexval.bval = (yytext[0] == 'f' ? FALSE : TRUE); return(BOOLCONST);}
{id}        {lexval.sval = newstring(yytext);return(ID);}
{sugar}     {return(yytext[0]);}
.           {printf("Line %d: ErrLessicale carattere %s non riconosciuto\n",line,yytext);errLessicale();}
%%
char *newstring(char *s)
{
  char *p;
  
  p = malloc(strlen(s)+1);
  strcpy(p, s);
  return(p);
}

void errLessicale(){
    exit(-4);
}
