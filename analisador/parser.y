%{
#include <stdio.h>
#include <math.h>
#include "lib/potrex.h"
#include "lib/escopo.h"
#include "lib/table.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;


%}

%union {
	double nValue; 	/* double value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	struct node * nodeValue;  /* A node abstraction on parse three */
	
	};

%token <sValue> ID
%token <nValue> NUMBER_LITERAL
%token <sValue> STRING_LITERAL
%token WHILE BLOCK_ENDWHILE FOR BLOCK_ENDFOR DO BLOCK_ENDDO BLOCK_END
%token IF BLOCK_ENDIF THEN ELSE
%token START FUNCTION PROCEDURE RETURN
%token PRINT
%token DIMENSION
%token <sValue> NUMBER STRING BOOL MAP TRUE FALSE
%token AND OR NOT
%token OP_GEQ OP_LEQ OP_EQ OP_NEQ
%token OP_INCREMENT OP_DECREMENT
%token <sValue> SUM_ASSIGN DIFFERENCE_ASSIGN PRODUCT_ASSIGN QUOTIENT_ASSIGN REMAINDER_ASSIGN

%start program

%type <nodeValue> stm stmlist declaration start program subprograms subprogram
%type <nodeValue> print print_strs str
%type <nodeValue> args argumentos argumento atom dimensions tipo_inicial tipo id ids func_call pars parameters assign init_opt ops_access
%type <nodeValue> assignment io while for if elseif condition block return
%type <nodeValue> exp exp_lv2 exp_lv3 exp_lv4 exp_lv5 exp_lv6 exp_lv7 exp_lv8

%% /* Inicio da segunda seção, onde colocamos as regras BNF */


program : {create_scope_stack(); printEscope();} declaration subprograms start { 
																					fprintf(yyout, "%s\n%s\n%s\n", $2->target_code, $3->target_code, $4->target_code);
																					freeNode($2);
																					freeNode($3);
																					freeNode($4);
																					pop();
								   												}
		;

subprograms : 						  	{ 
											$$ = createNode(""); 
										}
			| subprogram subprograms  	{
										   char *s = concat(3, $1->target_code, "\n", $2->target_code);
	                             		   freeNode($1);
	                             		   freeNode($2);
	                             		   $$ = createNode(s);
	                             		   free(s);
										}
			;

start : START '(' ')' '{' stmlist '}' BLOCK_END	{
													char * s = concat(3, "int main(){\n", $5->target_code, "return 0;\n}\n" );
													freeNode($5);
													$$ = createNode(s);
													free(s);
												}

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

tipo : NUMBER 	{ 
				  		$$ = createNode("double");
				  		free($1);
					}
	 | STRING 	{ 
				  		$$ = createNode("char*");    // também pode ser char[]
				  		free($1);
					}
	 | BOOL 		{}    // bool não existe, então 'int' (0 ou 1)?
	 | MAP		{}    // struct?
	 ;

argumentos : 							{ $$ = createNode(""); }
		   | args						{ $$ = $1; }
		   ;

args : argumento 						{ $$ = $1; } 
	 | argumento ',' args			{
	 											char* s = concat(3, $1->target_code, ", ", $3->target_code);
				 								freeNode($1);
												freeNode($3);
												$$ = createNode(s);
												free(s);
											}
	 ;

argumento : tipo_inicial ID  		{
												char* s = concat(3, $1->target_code, " ", $2);
												freeNode($1);
												free($2);
												$$ = createNode(s);
												free(s);
											}
		  ;

pars :									{ $$ = createNode(""); }
	 | parameters						{ $$ = $1; }
	 ;

parameters : exp 						{ $$ = $1; }
		   | parameters ',' exp 	{
		   									char* s = concat(3, $1->target_code, ", ", $3->target_code);
												freeNode($1);
												freeNode($3);
												$$ = createNode(s);
												free(s);
									 		}
		   ;

tipo_inicial : tipo					{ $$ = $1; }
		     | tipo dimensions		{
												char* s = concat(2, $1, $2->target_code);
											   freeNode($2);
											   free($1);
											   $$ = createNode(s);
											   free(s);
											} 
		     ;

//essa regra estaria certa par adimension?
/*
tipo[][] array 
a[2] = 3
a[10] = 4

int a[10];
a[3] = 2;
a[3] + 1

O array precisa ser apenas declarado numa linha, e em outra linha, iniciar os valores:
tipo[] array;
array = [args];
*/
dimensions : DIMENSION						{ $$ = createNode("[]"); }
           | DIMENSION dimensions		{
														char* s = concat(2, "[]", $2->target_code);
													   freeNode($2);
													   $$ = createNode(s);
													   free(s);
													} 
		     ;

stmlist : stm ';'				{
										char* s = concat(2, $1->target_code, ";\n");
										freeNode($1);
										$$ = createNode(s);
										free(s);
									}
		| stm ';' stmlist 	{
										char* s = concat(3, $1->target_code, ";\n", $3->target_code);
				 					 	freeNode($1);
										freeNode($3);
										$$ = createNode(s);
										free(s);
									}
		| while stmlist 		{
										char* s = concat(3, $1->target_code, "\n", $2->target_code);
				 					 	freeNode($1);
										freeNode($2);
										$$ = createNode(s);
										free(s);
									}
		| for stmlist 			{
										char* s = concat(3, $1->target_code, "\n", $2->target_code);
				 					 	freeNode($1);
										freeNode($2);
										$$ = createNode(s);
										free(s);
									}
		| if stmlist 			{
										char* s = concat(3, $1->target_code, "\n", $2->target_code);
				 					 	freeNode($1);
										freeNode($2);
										$$ = createNode(s);
										free(s);
									}
	    ;

stm : declaration 							{ $$ = $1; } // io (print), iterator (while, do, for), flowControl (if, switch)
	| assignment								{ $$ = $1; } 
	| exp                               { $$ = $1; }
	| block 										{ $$ = $1; }
	| io 											{ $$ = $1; }
	| return										{ $$ = $1; }
	;

atom : ID						{  // TODO ao invés de colocar string do id, fazer um lookup na tabela de símbolos e pegar seu valor
										$$ = createNode($1); 
								  		free($1);
									}
	 | ID ops_access 			{
										char* s = concat(2, $1, $2->target_code);
									   freeNode($2);
									   free($1);
									   $$ = createNode(s);
									   free(s);
									}
	 ;

ops_access : '[' exp ']'					{
														char* s = concat(3, "[", $2->target_code, "]");
													   freeNode($2);
													   $$ = createNode(s);
													   free(s);
													}
		   | '[' exp ']' ops_access		{
														char* s = concat(4, "[", $2->target_code, "]", $4->target_code);
													   freeNode($2);
													   freeNode($4);
													   $$ = createNode(s);
													   free(s);
													}
		   ;

assignment : atom assign exp				{
														char* s = concat(3, $1->target_code, $2->target_code, $3->target_code);
					 								   freeNode($1);
													   freeNode($2);
													   freeNode($3);
													   $$ = createNode(s);
													   free(s);
													}
				| atom assign '[' pars ']' {
														char* s = concat(5, $1->target_code, $2->target_code, "[", $4->target_code, "]");
													   freeNode($1);
													   freeNode($2);
													   freeNode($4);
													   $$ = createNode(s);
													   free(s);
													}
				; 

declaration : 									{ $$ = createNode(""); }
			| tipo_inicial ids				{
														char* s = concat(3, $1->target_code, " ", $2->target_code);
													   freeNode($1);
													   freeNode($2);
													   $$ = createNode(s);
													   free(s);
													}
			;

/** op 1, 2, 3 e 4 de declaração e inicialização 
* 1. type a;
* 2. type a, b, c;
* 3. type a = 10;
* 4. type a = 1, b = 2, c = 3;
* 5. int[] a = {2,3}; //todo
* a = b;
*/

ids :  id	               { $$ = $1; }
	|  id ',' ids	 			{
										char* s = concat(3, $1, ", ", $3);
									   free($1);
									   free($3);
									   $$ = createNode(s);
									   free(s);
									}
	;

id  : ID init_opt				{
										char* s = concat(2, $1, $2->target_code);
									   free($1);
									   freeNode($2);
									   $$ = createNode(s);
									   free(s);
									}
	;

init_opt : 			  			{ $$ = createNode(""); }
		 | assign exp 			{
		 								char* s = concat(4, " ", $1->target_code, " ", $2->target_code);
										freeNode($1);
										freeNode($2);
										$$ = createNode(s);
										free(s);
		 			   			}
		 ;

assign : '='        			{ $$ = createNode("="); }
	    | SUM_ASSIGN			{ $$ = createNode($1); free($1); }
	    | DIFFERENCE_ASSIGN	{ $$ = createNode($1); free($1); }
	    | PRODUCT_ASSIGN		{ $$ = createNode($1); free($1); }
	    | QUOTIENT_ASSIGN	{ $$ = createNode($1); free($1); }
	    | REMAINDER_ASSIGN	{ $$ = createNode($1); free($1); }
	    ;

while : WHILE condition block BLOCK_ENDWHILE	{
																char* s = concat(5, "while (", $2->target_code, "){\n", $3->target_code, "}");
															   freeNode($2);
															   freeNode($3);
															   $$ = createNode(s);
															   free(s);
															}
	  ;

for : FOR condition block BLOCK_ENDFOR 		{
																char* s = concat(5, "for (", $2->target_code, "){\n", $3->target_code, "}");
															   freeNode($2);
															   freeNode($3);
															   $$ = createNode(s);
															   free(s);
															}
    ;

if : IF condition block BLOCK_ENDIF							{
																			char* s = concat(5, "if(", $2->target_code, "){\n", $3->target_code, "}");
																		   freeNode($2);
																		   freeNode($3);
																		   $$ = createNode(s);
																		   free(s);
																		}
   | IF condition block BLOCK_ENDIF elseif 				{
																			char* s = concat(6, "if(", $2->target_code, "){\n", $3->target_code, "} ", $5->target_code);
																		   freeNode($2);
																		   freeNode($3);
																		   freeNode($5);
																		   $$ = createNode(s);
																		   free(s);
																		}
   ;

elseif : ELSE IF condition block BLOCK_ENDIF elseif	{
																			char* s = concat(6, "else if(", $3->target_code, "){\n", $4->target_code, "} ", $6->target_code);
																		   freeNode($3);
																		   freeNode($4);
																		   freeNode($6);
																		   $$ = createNode(s);
																		   free(s);
																		}
			| ELSE IF condition block BLOCK_ENDIF			{
																			char* s = concat(5, "else if(", $3->target_code, "){\n", $4->target_code, "}");
																		   freeNode($3);
																		   freeNode($4);
																		   $$ = createNode(s);
																		   free(s);
																		}
   	   | ELSE block BLOCK_ENDIF 							{
																			char* s = concat(3, "else {\n", $2->target_code, "}");
																		   freeNode($2);
																		   $$ = createNode(s);
																		   free(s);
																		}
	   ;

block : '{' stmlist '}' 			{
												char* s = concat(3, "{", $2->target_code, "}");
											   freeNode($2);
											   $$ = createNode(s);
											   free(s);
											}
	  ;

condition : '(' exp ')'				{
												char* s = concat(3, "(", $2->target_code, ")");
											   freeNode($2);
											   $$ = createNode(s);
											   free(s);
											}
		  ;

exp : exp_lv8 OR exp 				{
												char* s = concat(3, $1->target_code, " || ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
	| exp_lv8							{ $$ = $1; }
	;

exp_lv8 : exp_lv7 AND exp_lv8 	{
												char* s = concat(3, $1->target_code, " && ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv7						{ $$ = $1; }
		;

exp_lv7 : exp_lv6 OP_EQ exp_lv7	{
												char* s = concat(3, $1->target_code, " == ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv6 OP_NEQ exp_lv7	{
												char* s = concat(3, $1->target_code, " != ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv6						{ $$ = $1; }
		;

exp_lv6 : exp_lv5 '<' exp_lv6		{
												char* s = concat(3, $1->target_code, " < ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv5 OP_LEQ exp_lv6	{
												char* s = concat(3, $1->target_code, " <= ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv5 '>' exp_lv6		{
												char* s = concat(3, $1->target_code, " > ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv5 OP_GEQ exp_lv6	{
												char* s = concat(3, $1->target_code, " >= ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv5						{ $$ = $1; }
		;

exp_lv5 : exp_lv4 '+' exp_lv5		{
												char* s = concat(3, $1->target_code, " + ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv4 '-' exp_lv5		{
												char* s = concat(3, $1->target_code, " - ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv4						{ $$ = $1; }
		;

exp_lv4 : exp_lv3 '*' exp_lv4		{
												char* s = concat(3, $1->target_code, " * ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv3 '/' exp_lv4		{
												char* s = concat(3, $1->target_code, " / ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv3 '%' exp_lv4		{
												char* s = concat(3, $1->target_code, " % ", $3->target_code);
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											}
		| exp_lv3						{ $$ = $1;}
		;

exp_lv3 : NOT exp_lv3				{
												char* s = concat(2, "!", $2->target_code);
												freeNode($2);
												$$ = createNode(s);
												free(s);
											} // TODO está correto???
		| exp_lv2 '^' exp_lv2		{
												char* s = concat(6, "pow","(", $1->target_code, ",", $3->target_code, ")");
											   freeNode($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											} // TODO está correto???
		| exp_lv2						{ $$ = $1; }
		;

exp_lv2 : '(' exp ')'				{
												char* s = concat(3, "(", $2->target_code, ")");
												freeNode($2);
												$$ = createNode(s);
												free(s);
											}
		| atom OP_INCREMENT			{
												char* s = concat(2, $1->target_code, "++");
												freeNode($1);
												$$ = createNode(s);
												free(s);
											} 
		| atom OP_DECREMENT			{
												char* s = concat(2, $1->target_code, "--");
												freeNode($1);
												$$ = createNode(s);
												free(s);
											}
		| func_call					{ $$ = $1; }
		| NUMBER_LITERAL 			{
											char* str;
										   str = malloc(sizeof(char) * 1000); 
										   sprintf(str, "%lf", $1);
										   $$ = createNode(str);
										   free(str);
										}  // TODO STRING_LITERAL tambem cabe aqui? 
		| TRUE						{ 
											$$ = createNode($1);             // $$ = createNode("1")? C não tem true/false
							  				free($1);
							  			}
	 	| FALSE						{ 
											$$ = createNode($1);             // $$ = createNode("0")? C não tem true/false
							  				free($1);
							  			}
		| atom						{ $$ = $1; } 
		;

func_call : ID '(' pars ')'		{
												char* s = concat(4, $1, "(", $3->target_code, ")");
											   free($1);
											   freeNode($3);
											   $$ = createNode(s);
											   free(s);
											} // TODO ao invés de colocar string do id, fazer um lookup na tabela de símbolos e pegar seu valor
		  ;

io : print		{ $$ = $1; } // TODO open, close, printToFile ???
   ;

print : PRINT '(' print_strs ')'		{
													char* s = concat(3, "printf(\"", $3->target_code, "\")");
												   freeNode($3);
												   $$ = createNode(s);
												   free(s);
												}
      ;

print_strs : str 					{ $$ = $1; }
		   | str print_strs		{
		   								char* s = concat(2, $1->target_code, $2->target_code);
										  	freeNode($1);
										  	freeNode($2);
										  	$$ = createNode(s);
										  	free(s);
										}
		   ;

str : STRING_LITERAL		{ // remove aspas do fim
								   char* end = $1;
								   while(*(end + 1) != '\0') {
										end++;
								  	}
								   *end = '\0';

								   // + 1 para remover aspas do começo
								   $$ = createNode($1 + 1);
								   free($1);
								}
	| func_call				{ $$ = $1; }
	| NUMBER_LITERAL		{
									char* str;
								   str = malloc(sizeof(char) * 1000); 
								   sprintf(str, "%lf", $1);
								   $$ = createNode(str);
								   free(str);
								}
	| TRUE					{ $$ = createNode($1); free($1); }
	| FALSE					{ $$ = createNode($1); free($1); }
	| atom					{ $$ = $1; } 
	; // TODO como manda computar uma expressão aqui no meio e imprimir o resultado?

return : RETURN stm		{
									char * s = concat(3, "return ", $2->target_code, ";");
                   			freeNode($2);
                   			$$ = createNode(s);
                   			free(s);
                  		}
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