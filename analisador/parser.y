%{
#include <stdio.h>
#include <stdlib.h>
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
%token PRINT SCAN READ
%token DIMENSION
%token <sValue> NUMBER STRING BOOL CONTAINER TRUE FALSE
%token AND OR NOT
%token OP_GEQ OP_LEQ OP_EQ OP_NEQ
%token OP_INCREMENT OP_DECREMENT
%token <sValue> SUM_ASSIGN DIFFERENCE_ASSIGN PRODUCT_ASSIGN QUOTIENT_ASSIGN REMAINDER_ASSIGN

%start program

%type <nodeValue> stm stmlist declaration start program subprograms subprogram
%type <nodeValue> print print_arg scan read
%type <nodeValue> args argumentos argumento atom dimensions /*tipo_inicial*/ tipo id ids proc_func_call pars parameters assign init_opt op_access ops_access
%type <nodeValue> assignment container_decl container_decls io escope while for if elseif condition block return index
%type <nodeValue> exp exp_lv2 exp_lv3 exp_lv4 exp_lv5 exp_lv6 exp_lv7 exp_lv8

%% /* Inicio da segunda seção, onde colocamos as regras BNF */


program : {create_scope_stack(); create_table(); } declaration subprograms start { 
																					fprintf(yyout, "%s\n%s\n%s\n", $2->target_code, $3->target_code, $4->target_code);
																					freeNode($2);
																					freeNode($3);
																					freeNode($4);
																					pop();
																					//printEscope();
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

start : {push(create_container("start")); } START '(' ')' '{' stmlist '}' BLOCK_END	{
													char * s = concat(3, "int main(){\n", $6->target_code, "return 0;\n}\n" );
													freeNode($6);
													$$ = createNode(s);
													free(s);
													pop();
													//printEscope();
												}

/*
* Funcao: function myFunc(int a, string b, bool c) : number {instrucoes} end
* Procedimento: procedure myFunc(int a, string b, bool c) {instrucoes} end
* 
*/
subprogram  : FUNCTION ID  '(' argumentos ')' ':' tipo '{' stmlist '}' BLOCK_END  
				{
					char *s1 = concat(9, $7->target_code, " ", $2, " (", $4->target_code, ") ", "{\n", $9->target_code, "}\n");
					freeNode($7);
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

tipo : NUMBER 		{ 
				  		$$ = createNode("double");
				  		free($1);
					}
	 | STRING 		{ 
				  		$$ = createNode("char*");
				  		free($1);
					}
	 | BOOL 		{
						$$ = createNode("int");
				  		free($1);
					}    
	 | CONTAINER ID	{
						char *s = concat(2, "struct ", $2);
						free($2);
						$$ = createNode(s);
						free(s);
	 				}
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

argumento : tipo ID						{
											char* s = concat(3, $1->target_code, " ", $2);
											freeNode($1);
											free($2);
											$$ = createNode(s);
											free(s);
										}
		  | tipo dimensions ID  		{
											char* s = concat(4, $1->target_code, " ", $3, $2->target_code);
											freeNode($1);
											freeNode($2);
											free($3);
											$$ = createNode(s);
											free(s);
										}
		| tipo '*' ID					{
											char* s = concat(3, $1->target_code, " *", $3);
											freeNode($1);
											free($3);
											$$ = createNode(s);
											free(s);
										}
		  ;
		  ;

pars :									{ $$ = createNode(""); }
	 | parameters						{ $$ = $1; }
	 ;

parameters : exp 						{ $$ = $1; }
			| '*' exp               	{
											char* s = concat(2, "&", $2->target_code);
											freeNode($2);
											$$ = createNode(s);
											free(s);
										}
		   	| exp ',' parameters  		{
											char* s = concat(3, $1->target_code, ", ", $3->target_code);
											freeNode($1);
											freeNode($3);
											$$ = createNode(s);
											free(s);
										}
		   ;

/*tipo_inicial : tipo					{ $$ = $1; }
		     | tipo dimensions		{
										char* s = concat(2, $1->target_code, $2->target_code);
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
dimensions : '[' index ']'				    { $$ = createNode("[]"); }
           | '[' index ']' dimensions		{
											  char* s = concat(2, "[]", $2->target_code);
											  freeNode($2);
											  $$ = createNode(s);
											  free(s);
											} 
		     ;

index : 					{ $$ = createNode(""); }
	  | exp					{
							 char* s = concat(3, "[((int) ", $1->target_code, ")]");
							 freeNode($1);
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
		| stm ';' stmlist 		{
									char* s = concat(3, $1->target_code, ";\n", $3->target_code);
									freeNode($1);
									freeNode($3);
									$$ = createNode(s);
									free(s);
								}
		| escope					{
										char* s = concat(2, $1->target_code, "\n");
										freeNode($1);
										$$ = createNode(s);
										free(s);
									}
		| escope stmlist 		{
										char* s = concat(3, $1->target_code, "\n", $2->target_code);
				 					 	freeNode($1);
										freeNode($2);
										$$ = createNode(s);
										free(s);
									}
	    ;

stm : declaration 						{ $$ = $1; } // io (print), iterator (while, do, for), flowControl (if, switch)
	| assignment						{ $$ = $1; } 
	| exp                               { $$ = $1; }
	| block 							{ $$ = $1; }
	| io 								{ $$ = $1; }
	| return							{ $$ = $1; }
	;

escope : while             		{ $$ = $1; }
	   | for 					{ $$ = $1; }
	   | if  					{ $$ = $1; }
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
	 | ID '.' ID				{
									char* s = concat(3, $1, ".", $3);
									free($1);
									free($3);
									$$ = createNode(s);
									free(s);
	 							}
	 ;

ops_access : op_access					{ $$ = $1; }
		   | op_access ops_access		{
											char* s = concat(2, $1->target_code, $2->target_code);
											freeNode($1);
											freeNode($2);
											$$ = createNode(s);
											free(s);
										}
		   ;

op_access : '[' exp ']'			{
								 char* s = concat(3, "[((int) ", $2->target_code, ")]");
								 freeNode($2);
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
			| '*' atom assign exp			{
												char* s = concat(4, "*", $2->target_code, $3->target_code, $4->target_code);
												freeNode($2);
												freeNode($3);
												freeNode($4);
												$$ = createNode(s);
												free(s);
											}
			| atom assign '[' pars ']' 		{
												char* s = concat(5, $1->target_code, $2->target_code, "[", $4->target_code, "]");
												freeNode($1);
												freeNode($2);
												freeNode($4);
												$$ = createNode(s);
												free(s);
											}
				; 

declaration : 								{ $$ = createNode(""); }
			| tipo ids						{
												char* s = concat(3, $1->target_code, " ", $2->target_code);
												freeNode($1);
												freeNode($2);
												$$ = createNode(s);
												free(s);
											}
			| tipo dimensions ids			{
												char* s = concat(3, $1->target_code, " ", $3->target_code);
												freeNode($1);
												freeNode($2);
												freeNode($3);
												$$ = createNode(s);
												free(s);
											}
			| container_decl 				{$$ = $1;}
			;

/** op 1, 2, 3 e 4 de declaração e inicialização 
* 1. type a;
* 2. type a, b, c;
* 3. type a = 10;
* 4. type a = 1, b = 2, c = 3;
* 5. int[] a = [2,3];
* 6. 
* a = b;
*/

ids :  id	               		{ $$ = $1; }
	|  id ',' ids	 			{
									char* s = concat(3, $1->target_code, ", ", $3->target_code);
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
		 | assign '[' pars ']'	{
									char* s = concat(5, "[] ", $1->target_code, " {", $3->target_code, "}");
									freeNode($1);
									freeNode($3);
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

container_decl : CONTAINER ID '{' container_decls '}' 	{
														char* s = concat(5, "struct ", $2, "{\n", $4->target_code, "};");
														free($2);
														freeNode($4);
														$$ = createNode(s);
														free(s);
													}
		  ;

container_decls : declaration                        	{ $$ = $1; }
				| declaration ',' container_decls		{
															char* s = concat(3, $1->target_code, ",\n", $3->target_code);
															freeNode($1);
															freeNode($3);
															$$ = createNode(s);
															free(s);
														}
				;

// TODO container


/* loop2020:
if(a == 2 ){
  printf("dentro\n");
  scanf("%d", &a);
  goto loop2020;
}
  printf("fora\n"); */
while : WHILE condition block BLOCK_ENDWHILE	{
													char* loop_identifier = (char*) calloc(10000, sizeof(char));
													sprintf(loop_identifier, "loop%d", loop_id());

													remove_end_character($3->target_code);													
														
													char* final_str = concat(9, loop_identifier, ":", "if( ", $2->target_code, ")", 
														$3->target_code, "goto ", loop_identifier, ";\n}");
														
													$$ = createNode(final_str);
													free(final_str);
													freeNode($2);
													freeNode($3);
													free(loop_identifier);
												}
	  ;

for : FOR condition block BLOCK_ENDFOR 		{
																char* s = concat(3, "for ", $2->target_code, $3->target_code);
															   freeNode($2);
															   freeNode($3);
															   $$ = createNode(s);
															   free(s);
															}
    ;

if : IF condition block BLOCK_ENDIF							{
																			char* s = concat(3, "if ", $2->target_code, $3->target_code);
																		   freeNode($2);
																		   freeNode($3);
																		   $$ = createNode(s);
																		   free(s);
																		}
   | IF condition block BLOCK_ENDIF elseif 				{
																			char* s = concat(4, "if ", $2->target_code, $3->target_code, $5->target_code);
																		   freeNode($2);
																		   freeNode($3);
																		   freeNode($5);
																		   $$ = createNode(s);
																		   free(s);
																		}
   ;

elseif : ELSE IF condition block BLOCK_ENDIF elseif	{
																			char* s = concat(4, "else if ", $3->target_code, $4->target_code, $6->target_code);
																		   freeNode($3);
																		   freeNode($4);
																		   freeNode($6);
																		   $$ = createNode(s);
																		   free(s);
																		}
			| ELSE IF condition block BLOCK_ENDIF			{
																			char* s = concat(3, "else if ", $3->target_code, $4->target_code);
																		   freeNode($3);
																		   freeNode($4);
																		   $$ = createNode(s);
																		   free(s);
																		}
   	   | ELSE block BLOCK_ENDIF 							{
																			char* s = concat(2, "else ", $2->target_code);
																		   freeNode($2);
																		   $$ = createNode(s);
																		   free(s);
																		}
	   ;

block : { 
		 char* sname = (char*) calloc(10000, sizeof(char));
		 sprintf(sname, "block@%d", block_id());
		 push(create_container(sname)); //printEscope();
		} 
		 '{' stmlist '}' 			
											{	
											    char* s = concat(3, "{\n", $3->target_code, "}");
											    freeNode($3);
											    $$ = createNode(s);
											    free(s);

												s_container* c = pop();
												free(c->name);
												//printEscope();
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
		| exp_lv3 '%' exp_lv4				{
											   char* s = concat(5, "remainder (", $1->target_code, ", ", $3->target_code, ")");
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
		| proc_func_call					{ $$ = $1; }
		| NUMBER_LITERAL 			{
										char* str;
										str = malloc(sizeof(char) * 1000); 
										sprintf(str, "%lf", $1);
										$$ = createNode(str);
										free(str);
									}  // TODO STRING_LITERAL tambem cabe aqui? 
		| TRUE						{ 
										$$ = createNode("1");             // $$ = createNode("1")? C não tem true/false
										free($1); // TODO PRECISA DAR FREE
									}
	 	| FALSE						{ 
										$$ = createNode("0");             // $$ = createNode("0")? C não tem true/false
										free($1);
									}
		| atom						{ $$ = $1; } 
		;

proc_func_call : ID {push(create_container($1)); } '(' pars ')'		
											{
											   char* s = concat(4, $1, "(", $4->target_code, ")");
											   free($1);
											   freeNode($4);
											   $$ = createNode(s);
											   free(s);
											   pop();
											   //printEscope();
											} // TODO ao invés de colocar string do id, fazer um lookup na tabela de símbolos e pegar seu valor
		  ;

io : print		{ $$ = $1; } 
   | scan       { $$ = $1; }
   | read       { $$ = $1; }
   ;

// Potrex: scan(id);
// C simplificado: 
// scanf("%d", &v); 
scan: SCAN '(' ID ')' { 
						char* s = concat(3, "scanf(\"%lf\", &", $3, ")"); // TODO pegar o tipo do valor no scanf
						free($3);
						$$ = createNode(s);
						free(s);
					  }
	;
		
read :  READ '(' tipo ID ')'
						{
							char* s = build_scanf($3->target_code, $4);
							$$ = createNode(s);
							freeNode($3);
							free(s);
						}
	;


print : PRINT '(' print_arg ')'			
								{
									char* s = concat(3, "printf(", $3->target_code, ")");
									$$ = createNode(s);
									freeNode($3);
									free(s);
								}
      ;

print_arg :	STRING_LITERAL
									{
										char* s = build_printf($1, NULL, NULL);
										$$ = createNode(s);
										free($1);
										free(s);
									}
		  | STRING_LITERAL  ',' tipo ID	
									{
										char* s = build_printf($1, $3->target_code, $4);
										$$ = createNode(s);
										freeNode($3);
										free($1);
										free($4);
										free(s);	
									}
		  | tipo ID
									{
										char* s = build_printf(NULL, $1->target_code, $2);
										$$ = createNode(s);
										freeNode($1);
										free($2);
										free(s);
									}
		  ;		   



return : RETURN stm		{
							char * s = concat(2, "return ", $2->target_code);
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

	char* incl = "#include <stdio.h>\n#include <math.h>\n#include <stdlib.h>\n ";
	fprintf(yyout, "%s", incl);

    codigo = yyparse();

    fclose(yyin);
    fclose(yyout);

	return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}