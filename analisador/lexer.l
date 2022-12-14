digit           [0-9]
letter          [a-zA-Z]
letterAndDigit  [a-zA-Z0-9]

%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);
%}

%%

[ \s\t\n\r]           ;
{digit}+|[-]{digit}+|({digit}+.{digit}+)|[-]({digit}+.{digit}+)   {yylval.nValue = strtod(yytext, NULL); 
                                                                    return NUMBER_LITERAL;}
"true"                {yylval.sValue = strdup(yytext);
                        return(TRUE);}
"false"               {yylval.sValue = strdup(yytext);
                        return(FALSE);}
\"(\\.|[^"\\])*\"     {yylval.sValue = strdup(yytext); 
                         return STRING_LITERAL;}
"start"               {return(START);}
"procedure"           {return(PROCEDURE);}
"function"            {return(FUNCTION);}
"end"      				    {return(BLOCK_END);}
"return"              {return(RETURN);}
"print"               {return(PRINT);}
"scan"                {return(SCAN);}
"read"                {return(READ);}
"while"      			    {return(WHILE);}
"endwhile"      			{return(BLOCK_ENDWHILE);}
"do"      				    {return(DO);}
"enddo"      				  {return(BLOCK_ENDDO);} 
"for"      				    {return(FOR);}
"endfor"              {return(BLOCK_ENDFOR);}
"if"      				    {return(IF);}
"endif"               {return(BLOCK_ENDIF);}
"then"      			    {return(THEN);}
"else"      			    {return(ELSE);}
"{"                   {return(yytext[0]);}
"}"                   {return(yytext[0]);}
"("                   {return(yytext[0]);}
")"                   {return(yytext[0]);}
"["                   {return(yytext[0]);}
"]"                   {return(yytext[0]);}
";"      				      {return(yytext[0]);}
","                   {return(yytext[0]);}
":"                   {return(yytext[0]);}
"."                   {return(yytext[0]);}
"+"                   {return(yytext[0]);}
"-"                   {return(yytext[0]);}
"*"                   {return(yytext[0]);}
"/"                   {return(yytext[0]);}
"%"                   {return(yytext[0]);}
"^"                   {return(yytext[0]);}
"++"                  {return(OP_INCREMENT);}
"--"                  {return(OP_DECREMENT);}
"="					          {return(yytext[0]);}
"+="					        {return(SUM_ASSIGN);}
"-="					        {return(DIFFERENCE_ASSIGN);}
"*="					        {return(PRODUCT_ASSIGN);}
"/="					        {return(QUOTIENT_ASSIGN);}
"%="					        {return(REMAINDER_ASSIGN);}
">"					          {return(yytext[0]);}
"<"					          {return(yytext[0]);}
">="					        {return(OP_GEQ);}
"<="					        {return(OP_LEQ);}
"=="					        {return(OP_EQ);}
"=/="					        {return(OP_NEQ);}
"or"      			      {return(OR);}
"and"      			      {return(AND);}
"not"                 {return(NOT);}
"[]"					        {return(DIMENSION);}
"number"					    {yylval.sValue = strdup("number");
                        return(NUMBER);}
"string"					    {yylval.sValue = strdup("string");
                        return(STRING);}
"boolean"					    {yylval.sValue = strdup("boolean");
                        return(BOOL);}
"container"					  {return(CONTAINER);}
"null"                {return(NIL);}
 

(\/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/)|(\/\/.*) {printf("Comment: %s.\n", yytext);}

{letter}{letterAndDigit}*	{yylval.sValue = strdup(yytext); 
                           return ID;}
.                      {yyerror("invalid character");}

%%

#ifndef yywrap

int yywrap (void){
    return 1;
}

#endif