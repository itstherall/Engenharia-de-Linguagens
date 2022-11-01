%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
%}

%%

[ \t\n]               ;
[0-9]+           	    {yylval.iValue = atoi(yytext); 
                       return NUMBER;}
"while"      			    {return(WHILE);}
"endwhile"      			{return(BLOCK_ENDWHILE);}
"for"      				    {return(FOR);}
"endfor"              {return(BLOCK_ENDFOR);}
"if"      				    {return(IF);}
"endif"               {return(BLOCK_ENDIF);}
"end"      				    {return(BLOCK_END);}
"do"      				    {return(DO);}
"then"      			    {return(THEN);}
"else"      			    {return(ELSE);}
":"                   {return(DP);}
";"      				      {return(SEMI);}
","                   {return(COL);}
"+"                   {return(OP_AD);}
"-"                   {return(OP_SUB);}
"*"                   {return(OP_MULT);}
"/"                   {return(OP_DIV);}
"="					          {return(ASSIGN);}

[a-zA-Z][a-zA-Z0-9]*	{yylval.sValue = strdup(yytext); 
                       return ID;}
.                      {yyerror("invalid character");}

%%

#ifndef yywrap

int yywrap (void){
    return 1;
}

#endif