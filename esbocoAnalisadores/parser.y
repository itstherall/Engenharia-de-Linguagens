%{
#include <stdio.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%union {
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	};

%token <sValue> ID
%token <iValue> NUMBER
%token WHILE BLOCK_BEGIN BLOCK_END DO IF THEN ELSE SEMI ASSIGN

%start prog

%type <sValue> stm

%% /* Inicio da segunda seção, onde colocamos as regras BNF */

program : declarations subprograms {}
		;

subprograms : subprogram			{}
			| subprogram subprograms  {}
			;

subprogram  : FUNCTION ID AP arguments FP DP type AC stmlist FC BLOCK_END
		    | PROCEDURE ID AP arguments FP AC  stmlist FC BLOCK_END
			;

type : NUMBER | STRING | BOOL | MAP
	 ;

arguments : argument 						{}
		  | arguments COL argument 			{}
		  ;

argument : type ID  						{}
		 ;


stmlist : stm								{}
		| stmlist SEMI stm   				{}
	    ;

stm : declaration 							{}
	| while									{}
	| if 									{}
	| block 								{}
	;

declaration : type ids
			;

ids :  id  SEMI    			{}
	|  id COL ids	 		{}
	;

id  : ID init_opt 	{}
	;

init_opt : 
		 | ASSIGN ID
		 ;


while : WHILE condition block WHILE_BLOCK_END 	{}
	  ;


if : IF condition block IF_BLOCK_END			{}
   | IF condition block ELSE IF condition block IF_BLOCK_END			{}
   | IF condition block ELSE block IF_BLOCK_END {}
   ;

block : AC stmlist FC 			{}
	  ;

condition : AP bool_exp FP		{}
		  | AP rel_exp FP		{}
		  ;
%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}