%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
%}

%%

[ \t\n]               ;
[0-9]+           	    {yylval.iValue = atoi(yytext); 
                       return NUMBER_LITERAL;}
"procedure"           {return(PROCEDURE);}
"function"            {return(FUNCTION);}
"end"      				    {return(BLOCK_END);}
"return"              {return(RETURN);}
"while"      			    {return(WHILE);}
"endwhile"      			{return(BLOCK_ENDWHILE);}
"for"      				    {return(FOR);}
"endfor"              {return(BLOCK_ENDFOR);}
"if"      				    {return(IF);}
"endif"               {return(BLOCK_ENDIF);}
"then"      			    {return(THEN);}
"else"      			    {return(ELSE);}
"do"      				    {return(DO);}
"{"                   {return(AC);}
"}"                   {return(FC);}
"("                   {return(AP);}
")"                   {return(FP);}
"["                   {return(ACC);}
"]"                   {return(FCC);}
";"      				      {return(SEMI);}
","                   {return(COL);}
":"                   {return(DP);}
"+"                   {return(OP_AD);}
"-"                   {return(OP_SUB);}
"*"                   {return(OP_MULT);}
"/"                   {return(OP_DIV);}
"%"                   {return(REST_DIV);}
"++"                  {return(OP_INCREMENT);}
"--"                  {return(OP_DECREMENT);}
"="					          {return(ASSIGN);}
">"					          {return(OP_LARGER);}
"<"					          {return(OP_SMALLER);}
">="					        {return(OP_LEQ);}
"<="					        {return(OP_SEQ);}
"=="					        {return(OP_EQ);}
"=/="					        {return(OP_NEQ);}
"or"      			      {return(OR);}
"and"      			      {return(AND);}
(\[[0-9]+\]|\[\])     {return(ARRAYACESS)}
"not"                 {return(NOT);}
"[]"					        {return(DIMENSION);}
"number"					    {return(NUMBER);}
"string"					    {return(STRING);}
"boolean"					    {return(BOOL);}
"map"					        {return(MAP);}
 

(\/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/)|(\/\/.*) {printf("Comment: %s.\n", yytext);}

[a-zA-Z][a-zA-Z0-9]*	{yylval.sValue = strdup(yytext); 
                       return ID;}
.                      {yyerror("invalid character");}

%%

#ifndef yywrap

int yywrap (void){
    return 1;
}

#endif