%{
#include <stdio.h>
#include "../lib/potrex.h"

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
%token <iValue> NUMBER_LITERAL
%token <sValue> STRING_LITERAL
%token WHILE BLOCK_ENDWHILE FOR BLOCK_ENDFOR DO BLOCK_ENDDO BLOCK_END
%token IF BLOCK_ENDIF THEN ELSE
%token FUNCTION PROCEDURE RETURN
%token PRINT
%token DIMENSION
%token NUMBER STRING BOOL MAP
%token TRUE FALSE AND OR NOT
%token OP_GEQ OP_LEQ OP_EQ OP_NEQ
%token OP_INCREMENT OP_DECREMENT
%token SUM_ASSIGN DIFFERENCE_ASSIGN PRODUCT_ASSIGN QUOTIENT_ASSIGN REMAINDER_ASSIGN

%start program

%type <sValue> stm

%% /* Inicio da segunda seção, onde colocamos as regras BNF */

program : declaration subprograms {printf("program\n");}
		;

subprograms : subprogram			  {printf("subprogram\n");}
			| subprogram subprograms  {printf("subprograms\n");}
			;

/*
* Funcao: function myFunc(int a, string b, bool c) : number {instrucoes} end
* Procedimento: procedure myFunc(int a, string b, bool c) {instrucoes} end
*/
subprogram  : FUNCTION ID '(' argumentos ')' ':' tipo '{' stmlist '}' BLOCK_END  {printf("function id (arg) : tipo {stmlist} end\n");}
		    | PROCEDURE ID '(' argumentos ')' '{' stmlist '}' BLOCK_END			{printf("procedure id (arg) {stmlist} end\n");}
			;

tipo : NUMBER 	{printf("number\n");}
	 | STRING 	{printf("string\n");}
	 | BOOL 	{printf("bool\n");}
	 | MAP		{printf("map\n");}
	 ;

argumentos : 
		   | argumento 						    {}
		   | argumentos ',' argumento			{}
		   ;

argumento : tipo_inicial ID  					{}
		  ;

parameters : exp 							{}
		   | parameters ',' exp 			{}
		   ;

tipo_inicial : tipo
		     | tipo dimensions
		     ;

//essa regra estaria certa par adimension?
/*
tipo[][] array 
a[2] = 3
a[10] = 4

int a[10];
a[3] = 2;
a[3] + 1
*/
dimensions : DIMENSION
           | DIMENSION dimensions 
		   ;

stmlist : stm ';'							{}
		| stm ';' stmlist 					{}
	    ;

stm : declaration 							{} // io (print), iterator (while, do, for), flowControl (if, switch)
	| atom assign exp						{} 
	| while									{}
	| for									{}
	| if 									{}
	| block 								{}
	| io 									{}
	| RETURN stm;
	;

atom : ID						{} 
	 | ID ops_access 				{} 
	 ;

ops_access : '[' exp ']'				{}
		   | '[' exp ']' ops_access		{}
		   ;

declaration : 								{printf("no declarations\n");}
			| tipo_inicial ids				{printf("tipo ids\n");}
			;

/** op 1, 2, 3 e 4 de declaração e inicialização 
* 1. type a;
* 2. type a, b, c;
* 3. type a = 10;
* 4. type a = 1, b = 2, c = 3;
* 5. int[] a = {2,3}; //todo
* a = b;
*/

ids :  id	                {printf("id;\n");}
	|  id ',' ids	 		{printf("id, \n");}
	;

id  : ID init_opt	{printf("id init_op\n");}
	;

init_opt : 
		 | assign exp {printf(" = exp\n");}
		 ;

assign : '='
	   | SUM_ASSIGN
	   | DIFFERENCE_ASSIGN
	   | PRODUCT_ASSIGN
	   | QUOTIENT_ASSIGN
	   | REMAINDER_ASSIGN
	   ;

while : WHILE condition block BLOCK_ENDWHILE	{}
	  ;

for : FOR condition block BLOCK_ENDFOR 		{}
    ;

if : IF condition block BLOCK_ENDIF			{}
   | IF condition block BLOCK_ENDIF elseif 	{}
   ;

elseif : ELSE IF condition block BLOCK_ENDIF elseif		{}
   	   | ELSE block BLOCK_ENDIF 						{}
	   ;

block : '{' stmlist '}' 			{}
	  ;

condition : '(' exp ')'		{}
		  ;

exp : exp_lv8 OR exp 	{}
	| exp_lv8			{}
	;

exp_lv8 : exp_lv7 AND exp_lv8 	{}
		| exp_lv7				{}
		;

exp_lv7 : exp_lv6 OP_EQ exp_lv7		{}
		| exp_lv6 OP_NEQ exp_lv7	{}
		| exp_lv6					{}
		|

exp_lv6 : exp_lv5 '<' exp_lv6		{}
		| exp_lv5 OP_LEQ exp_lv6	{}
		| exp_lv5 '>' exp_lv6		{}
		| exp_lv5 OP_GEQ exp_lv6	{}
		| exp_lv5					{}
		;

exp_lv5 : exp_lv4 '+' exp_lv5		{}
		| exp_lv4 '-' exp_lv5		{}
		| exp_lv4
		;

exp_lv4 : exp_lv3 '*' exp_lv4		{}
		| exp_lv3 '/' exp_lv4		{}
		| exp_lv3 '%' exp_lv4		{}
		| exp_lv3					{}
		;

exp_lv3 : NOT exp_lv3				{} // TODO está correto???
		| exp_lv2 '^' exp_lv2		{} // TODO está correto???
		| exp_lv2					{}
		;

exp_lv2 : '(' exp ')'				{}
		| ID '(' ')'				{} 	// retorno de função sem parâmetros
		| ID '(' parameters ')'		{} 	// retorno de função com parâmetros
		| atom OP_INCREMENT			{} 
		| atom OP_DECREMENT			{}
		| NUMBER_LITERAL 			{}  // TODO STRING_LITERAL tambem cabe aqui? 
		| TRUE						{}
	 	| FALSE						{}
		| atom						{}
		;

io : print // TODO open, close, printToFile ???
   ;

print : PRINT '(' '"' STRING_LITERAL '"' ')' // TODO permitir que variáveis sejam impressas
	  ;

%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}