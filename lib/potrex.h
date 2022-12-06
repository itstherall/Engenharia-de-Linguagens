#ifndef H_POTREX
#define H_POTREX

#include <stdlib.h>
#include <stdio.h>

/* TODO Tabela de simbolos */


/* TODO pilha */


/* Tipos existentes na linguagem */
typedef enum{
    number, 
    boolean,
    string, 
    map
} e_primitive_type;

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

s_node * createNode(char *, char *);

#endif