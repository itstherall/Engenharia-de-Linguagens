#ifndef H_POTREX
#define H_POTREX

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/* Tipos existentes na linguagem */
typedef enum primitive_type { // TODO deveria ser um union??
    number, 
    boolean,
    string, 
    map
} e_primitive_type;


/* TODO Tabela de simbolos */
typedef struct symbol{
    char* id;
    e_primitive_type type;

}s_symbol;

typedef struct symbol_table{
    s_symbol symbol;
    s_symbol* next_symbol;
    int size;
} s_symbol_table;


/* Nó que abstrai informações a respeito dos terminais e não terminais */
typedef struct node {
    /* Código alvo (C simplificado) */
    char* target_code;

    /* Tipo atual da terminal/não-terminal*/
    e_primitive_type type;

    /* Checagem da existência de retorno dos blocos */
    int return_check;

} s_node;
 
void freeNode(s_node *);

s_node * createNode(char *);

char* concat(int count, ...);

s_stack* create_stack();

#endif