%{
  #include <stdio.h>
%}

%%

[ \t\n]               ;
[0-9]+           	    {printf("NUMBER(%s)\n",yytext);}
"procedure"           {printf("PROCEDURE\n");}
"function"            {printf("FUNCTION\n");}
"end"      				    {printf("BLOCK_END\n");}
"return"              {printf("RETURN\n");}
"while"      			    {printf("WHILE\n");}
"endwhile"      			{printf("BLOCK_ENDWHILE\n");}
"for"      				    {printf("FOR\n");}
"endfor"              {printf("BLOCK_ENDFOR\n");}
"if"      				    {printf("IF\n");}
"endif"               {printf("BLOCK_ENDIF\n");}
"then"      			    {printf("THEN\n");}
"else"      			    {printf("ELSE\n");}
"do"      				    {printf("DO\n");}
"{"                   {printf("AC\n");}
"}"                   {printf("FC\n");}
"("                   {printf("AP\n");}
")"                   {printf("FP\n");}
";"      				      {printf("SEMI\n");}
","                   {printf("COL\n");}
":"                   {printf("DP\n");}
"+"                   {printf("OP_AD\n");}
"-"                   {printf("OP_SUB\n");}
"*"                   {printf("OP_MULT\n");}
"/"                   {printf("OP_DIV\n");}
"%"                   {printf("REST_DIV\n");}
"++"                  {printf("OP_INCREMENT\n");}
"--"                  {printf("OP_DECREMENT\n");}
"="					          {printf("ASSIGN\n");}
">"					          {printf("OP_LARGER\n");}
"<"					          {printf("OP_SMALLER\n");}
">="					        {printf("OP_LEQ\n");}
"<="					        {printf("OP_SEQ\n");}
"=="					        {printf("OP_EQ\n");}
"=/="					        {printf("OP_NEQ\n");}
"or"      			      {printf("OR\n");}
"and"      			      {printf("AND\n");}
"[]"					        {printf("DIMENSION\n");}
"number"					    {printf("NUMBER\n");}
"string"					    {printf("STRING\n");}
"boolean"					    {printf("BOOL\n");}
"map"					        {printf("MAP\n");}
(\/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/)|(\/\/.*) {printf("Comment: %s.\n", yytext);}
(\[[0-9]+\]|\[\])     {printf("ARRAYACESS\n")} 

[a-zA-Z][a-zA-Z0-9]*	{printf("ID(%s)\n",yytext);}
.                     {printf("invalid character");}

%%

#ifndef yywrap

int yywrap (void){
    return 1;
}

#endif

int main(void)
{
  yylex();  
  return 0;
}