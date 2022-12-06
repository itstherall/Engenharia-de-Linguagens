%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
%}

%%

[ \t]                   ;
\n                      {yylineno++;}
"funcao"                {return FUNCAO;}
"fim_funcao"            {return FIMFUNCAO;}
"se"                    {return SE;}
"entao"                 {return ENTAO;}
"senao"                 {return SENAO;}
"fim_se"                {return FIMSE;}
"programa"              {return PROGRAMA;}
"fim_programa"          {return FIMPROGRAMA;}
"escreva"               {return ESCREVA;}
"retorne"               {return RETORNO;}
"("                     {return yytext[0];}
")"                     {return yytext[0];}
","                     {return yytext[0];}
":"                     {return yytext[0];}
";"                     {return yytext[0];}
"bool"                  {yylval.sValue = strdup("bool"); 
                         return TYPE;}
\"[a-zA-Z0-9 é]*\"      {yylval.sValue = strdup(yytext); 
                         return STRING_LIT;}
"verdadeiro"            {yylval.sValue = strdup(yytext); 
                         return BOOL_LIT;}                       
"falso"                 {yylval.sValue = strdup(yytext); 
                         return BOOL_LIT;}                       
[a-zA-Z][a-zA-Z0-9]*    {yylval.sValue = strdup(yytext); 
                         return ID;}
.                       {yyerror("Invalid character");}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif