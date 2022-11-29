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
%token <iValue> NUMBER_LITERAL
%token <sValue> STRING_LITERAL
%token WHILE BLOCK_ENDWHILE  BLOCK_ENDFOR  IF BLOCK_ENDIF  BLOCK_END
%token FOR DO THEN ELSE
%token FUNCTION PROCEDURE RETURN
%token DIMENSION
%token NUMBER STRING BOOL MAP
%token TRUE FALSE AND OR NOT
%token OP_LEQ OP_SEQ OP_EQ OP_NEQ
%token OP_INCREMENT OP_DECREMENT

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

/**
* Por que não: argumento ',' argumentos?
*/
argumentos : 
		   | argumento 						    {}
		   | argumentos ',' argumento			{}
		   ;

/**
* Renomear para abstract_type ou composite_type
*/
argumento : tipo_inicial ID  					{}
		  ;

parametros : id 						{}
		   | parametros ',' id 			{}
		   ;

tipo_inicial : tipo
		     | tipo dimensions
		     ;

//essa regra estaria certa par adimension?
/* Creio que sim, so precisa imaginar como alocar espaço para cada [] */
/*
tipo[][] array 
a[2] = 3
a[10] = 4

int a[10];
a[3] = 2;
a[3] + 1

Como seria para alocar essas dimensões no sentido da implementação?
*/
dimensions : DIMENSION
           | DIMENSION dimensions 
		   ;

stmlist : stm ';'							{}
		| stm ';' stmlist 					{}
	    ;

/**
* Podemos ter funções dentro de funções?
*/
stm : declaration 							{} // io, print, iterator
	| while									{}
	| for									{}
	| if 									{}
	| block 								{}
	/* | function_call							{}  */
	/* | assign								{} ? */
	|
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
//		 | '=' ID {printf(" = id\n");}
		 | '=' ID '(' parametros ')' {printf(" = id(par)\n");}
		 | '=' arth_exp {printf(" = arth_exp\n");}
		 | '=' bool_exp {printf(" = bool_exp\n");}
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

condition : '(' bool_exp ')'		{}
		  ;

bool_exp : bool_term AND bool_exp {}
		 | bool_term OR bool_exp  {}
		 | bool_term			  {}
		 ;

bool_term : NOT bool_factor       {}
		  | bool_factor           {}
		  ;

bool_factor : TRUE                {}
		 	| FALSE               {} 
			| '(' bool_exp ')'      {} // TODO (exp)
		 	| rel_exp             {}// TODO colocar ID aqui??
			;
|

rel_exp : rel_term rel_op rel_term {}
		;

rel_term: arth_exp {}
        | ID '(' parametros ')' {} // TODO
		;

rel_op : OP_EQ      {} // igual
	   | OP_NEQ     {} // Diferente
	   | '>'  		{} // maior
	   | '<' 		{} // menor
	   | OP_LEQ     {} // maior igual
	   | OP_SEQ     {} // menor igual
	   ;

/*convenção factores são coisas multiplica|divide (mais em baixo na arv, maior prioridade)
            termos soma|diminui
*/
arth_exp : arth_term '+' arth_exp      {}
		 | arth_term '-' arth_exp 	 {}
		 | arth_term					 {}
		 ;
 
arth_term : arth_factor '*' arth_term {}
	      | arth_factor '/' arth_term  {}
	      | arth_factor					  {}
	      ;

arth_factor : '(' arth_exp ')'   {}
			| NUMBER_LITERAL   {}// TODO colocar ID aqui??
			;
 
 

%% /* Fim da segunda seção */

int main (void) {
	return yyparse();
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}