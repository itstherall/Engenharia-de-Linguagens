%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
%}

%%

[ \s\t\n\r]           ;
[0-9]+           	    {yylval.iValue = atoi(yytext); 
                       return NUMBER_LITERAL;}
"true"                {return(TRUE);}
"false"               {return(FALSE);}
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
"{"                   {return(yytext[0]);}
"}"                   {return(yytext[0]);}
"("                   {return(yytext[0]);}
")"                   {return(yytext[0]);}
"["                   {return(yytext[0]);}
"]"                   {return(yytext[0]);}
";"      				      {return(yytext[0]);}
","                   {return(yytext[0]);}
":"                   {return(yytext[0]);}
"+"                   {return(yytext[0]);}
"-"                   {return(yytext[0]);}
"*"                   {return(yytext[0]);}
"/"                   {return(yytext[0]);}
"%"                   {return(yytext[0]);}
"++"                  {return(OP_INCREMENT);}
"--"                  {return(OP_DECREMENT);}
"="					          {return(yytext[0]);}
">"					          {return(yytext[0]);}
"<"					          {return(yytext[0]);}
">="					        {return(OP_LEQ);}
"<="					        {return(OP_SEQ);}
"=="					        {return(OP_EQ);}
"=/="					        {return(OP_NEQ);}
"or"      			      {return(OR);}
"and"      			      {return(AND);}
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