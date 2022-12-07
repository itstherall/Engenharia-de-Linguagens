%{
#include <stdio.h>
#include "lib/potrex.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;



%}

%union {
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	struct node * nodeValue;  /* ??? */
	};

%token <sValue> ID
%token <iValue> NUMBER_LITERAL
%token <sValue> STRING_LITERAL
%token WHILE BLOCK_ENDWHILE FOR BLOCK_ENDFOR DO BLOCK_ENDDO BLOCK_END
%token IF BLOCK_ENDIF THEN ELSE
%token FUNCTION PROCEDURE RETURN
%token PRINT
%token DIMENSION
%token <sValue> NUMBER STRING BOOL MAP
%token TRUE FALSE AND OR NOT
%token OP_GEQ OP_LEQ OP_EQ OP_NEQ
%token OP_INCREMENT OP_DECREMENT
%token <sValue> SUM_ASSIGN DIFFERENCE_ASSIGN PRODUCT_ASSIGN QUOTIENT_ASSIGN REMAINDER_ASSIGN

%start program

%type <sValue> assign tipo
%type <nodeValue> stm stmlist declaration program subprograms subprogram 
%type <nodeValue> args argumentos argumento atom tipo_inicial
%type <nodeValue> assignment exp exp_lv2 exp_lv3 exp_lv4 exp_lv5 exp_lv6 exp_lv7 exp_lv8

%% /* Inicio da segunda seção, onde colocamos as regras BNF */

program : declaration subprograms {fprintf(yyout, "%s\n%s", $1->target_code, $2->target_code);
								   freeNode($1);
                      			   freeNode($2);
								   }
		;

subprograms : subprogram			  {$$ = $1;}
			| subprogram subprograms  {char *s = concat(3, $1->target_code, "\n", $2->target_code);
                             		   freeNode($1);
                             		   freeNode($2);
                             		   $$ = createNode(s);
                             		   free(s);
									  }
			;

/*
* Funcao: function myFunc(int a, string b, bool c) : number {instrucoes} end
* Procedimento: procedure myFunc(int a, string b, bool c) {instrucoes} end
*/
subprogram  : FUNCTION ID '(' argumentos ')' ':' tipo '{' stmlist '}' BLOCK_END  
				{
					char *s1 = concat(9, $7, " ", $2, " (", $4->target_code, ") ", "{\n", $9->target_code, "}\n");
					free($7);
					free($2);
					freeNode($4);
					freeNode($9);
					$$ = createNode(s1);
					free(s1);
				}
		    | PROCEDURE ID '(' argumentos ')' '{' stmlist '}' BLOCK_END	
				{
					char *s1 = concat(8, "void ", $2, " (", $4->target_code, ") ", "{\n", $7->target_code, "}\n");
					free($2);
					freeNode($4);
					freeNode($7);
					$$ = createNode(s1);
					free(s1);
				}
			;

tipo : NUMBER 	{ $$ = $1;
				  free($1);}
	 | STRING 	{ $$ = $1;
				  free($1);}
	 | BOOL 	{ $$ = $1;
				  free($1);}
	 | MAP		{$$ = $1;
				  free($1);}
	 ;

argumentos : 					{$$ = createNode("");}
		   | args				{$$ = $1;}
		   ;

args : argumento 					{$$ = $1;}
	 | argumento ',' args			{char* s = concat(3, $1->target_code, ", ", $3->target_code);
	 								 freeNode($1);
									 freeNode($3);
									 $$ = createNode(s);
									 free(s);
									}
	 ;

argumento : tipo_inicial ID  		{char* s = concat(3, $1->target_code, " ", $2);
									 freeNode($1);
									 free($2);
									 $$ = createNode(s);
									 free(s);
									}
		  ;

parameters : exp 							{}
		   | parameters ',' exp 			{}
		   ;

tipo_inicial : tipo					{$$ = createNode($1);
									 free($1);}
		     | tipo dimensions		{}
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
dimensions : DIMENSION					{}
           | DIMENSION dimensions		{}
		   ;

stmlist : stm ';'			{char* s = concat(2, $1->target_code, ";\n");
							freeNode($1);
							$$ = createNode(s);
							free(s);
							}
		| stm ';' stmlist 	{char* s = concat(3, $1->target_code, ";\n", $3->target_code);
	 					 	 freeNode($1);
							 freeNode($3);
							 $$ = createNode(s);
							 free(s);
							}
	    ;

stm : declaration 							{} // io (print), iterator (while, do, for), flowControl (if, switch)
	| assignment							{ $$ = $1; } 
	| while									{}
	| for									{}
	| if 									{}
	| block 								{}
	| io 									{}
	| return								{}
	;

atom : ID						{ $$ = createNode($1); } 
	 | ID ops_access 			{} 
	 ;

ops_access : '[' exp ']'				{}
		   | '[' exp ']' ops_access		{}
		   ;

assignment : atom assign exp		{char* s = concat(3, $1->target_code, $2, $3->target_code);
	 								 freeNode($1);
									 freeNode($3);
									 $$ = createNode(s);
									 free(s);}

declaration : 								{$$ = createNode("");}
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

assign : '='        { $$ = &yytext[0]; }
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
	| exp_lv8			{ $$ = $1; }
	;

exp_lv8 : exp_lv7 AND exp_lv8 	{}
		| exp_lv7				{ $$ = $1; }
		;

exp_lv7 : exp_lv6 OP_EQ exp_lv7		{}
		| exp_lv6 OP_NEQ exp_lv7	{}
		| exp_lv6					{ $$ = $1; }
		;

exp_lv6 : exp_lv5 '<' exp_lv6		{}
		| exp_lv5 OP_LEQ exp_lv6	{}
		| exp_lv5 '>' exp_lv6		{}
		| exp_lv5 OP_GEQ exp_lv6	{}
		| exp_lv5					{ $$ = $1; }
		;

exp_lv5 : exp_lv4 '+' exp_lv5		{}
		| exp_lv4 '-' exp_lv5		{}
		| exp_lv4					{ $$ = $1; }
		;

exp_lv4 : exp_lv3 '*' exp_lv4		{}
		| exp_lv3 '/' exp_lv4		{}
		| exp_lv3 '%' exp_lv4		{}
		| exp_lv3					{ $$ = $1;}
		;

exp_lv3 : NOT exp_lv3				{} // TODO está correto???
		| exp_lv2 '^' exp_lv2		{} // TODO está correto???
		| exp_lv2					{ $$ = $1; }
		;

exp_lv2 : '(' exp ')'				{}
		| ID '(' ')'				{} 	// retorno de função sem parâmetros
		| ID '(' parameters ')'		{} 	// retorno de função com parâmetros
		| atom OP_INCREMENT			{} 
		| atom OP_DECREMENT			{}
		| NUMBER_LITERAL 			{ char * str;
									  sprintf(str, "%d", $1);
									  $$ = createNode(str);
									}  // TODO STRING_LITERAL tambem cabe aqui? 
		| TRUE						{}
	 	| FALSE						{}
		| atom						{}
		;

io : print // TODO open, close, printToFile ???
   ;

print : PRINT '(' '"' STRING_LITERAL '"' ')' // TODO permitir que variáveis sejam impressas
	  ;

return : RETURN stm					{}
	   ;
	   
%% /* Fim da segunda seção */

int main (int argc, char ** argv) {
 	int codigo;

    if (argc != 3) {
       printf("Usage: $./compiler input.txt output.txt\nClosing application...\n");
       exit(0);
    }
    
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    codigo = yyparse();

    fclose(yyin);
    fclose(yyout);

	return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}