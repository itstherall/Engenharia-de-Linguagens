#ifndef H_POTREX
#define H_POTREX

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


/* Tipos existentes na linguagem */
typedef enum primitive_type {
    number, 
    boolean,
    string, 
    map
} e_primitive_type;

/* TODO pilha */
typedef struct block_element{

    /* Identificador do elemento */
    char* id;
} s_block_element;

typedef struct scope{

    /* Todos os elementos de um escopo */
    s_block_element* block_elements;

    /* Tamanho atual do escopo */
    int scope_size;

    /* Nome do escopo */
    char* name;
} s_scope;

typedef struct stack{
    s_scope* scopes;
    int size;
} s_stack;


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

void add_scope_to_stack(s_stack* stack, s_scope* scope);

int remove_scope_from_stack(s_stack* stack, s_scope* scope);

int scope_contains(s_scope* scope, s_block_element* element);

void add_element_to_scope(s_scope* scope, s_block_element* element);

void remove_element_from_scope(s_scope* scope, s_block_element* element);

#endif