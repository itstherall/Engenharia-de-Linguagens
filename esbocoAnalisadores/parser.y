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

%start lines

%token <sValue> ID
%token <iValue> NUMBER_LITERAL
%token WHILE BLOCK_ENDWHILE FOR BLOCK_ENDFOR DO IF BLOCK_ENDIF THEN ELSE 
%token SEMI ASSIGN COL DP FUNCTION PROCEDURE RETURN AP FP AC FC 
%token DIMENSION AND OP_AD OP_DIV OP_SUB OP_MULT
%token NUMBER STRING BOOL MAP
%token TRUE FALSE

%start prog

%type <sValue> stm

%% /* Inicio da segunda seção, onde colocamos as regras BNF */

program : declaration subprograms {}
		;

subprograms : subprogram			  {}
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

argument : init_type ID  						{}
		 ;

init_type : type
		  | type dimensions
		  ;

dimensions : DIMENSION
           | DIMENSION dimensions
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


while : WHILE condition block BLOCK_ENDWHILE{}
	  ;

for : FOR condition block BLOCK_ENDFOR{}
    ;

if : IF condition block BLOCK_ENDIF			{}
   | IF condition block BLOCK_ENDIF elseif 	{}
   ;

elseif : ELSE IF condition block BLOCK_ENDIF elseif		{}
   	   | ELSE block BLOCK_ENDIF 						{}
	   ;

block : AC stmlist FC 			{}
	  ;

condition : AP bool_exp FP		{}
		  | AP rel_exp FP		{}
		  ;

bool_exp : TRUE
		 | FALSE
		 | rel_exp
		 | bool_exp AND
		 ;

rel_exp : arth_exp rel_op //and, or 
		;

arth_exp : arth_exp OP_AD arth_term
		 | arth_exp OP_SUB arth_term
		 | arth_exp
		 ;
 
arth_term : arth_term OP_MULT arth_factor
	      | arth_term OP_DIV arth_factor
	      | arth_term
	      ;

arth_factor : AP arth_exp FP
			| ID
			;



%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}