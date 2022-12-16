#ifndef H_POTREX
#define H_POTREX

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Tipos existentes na linguagem */
typedef enum primitive_type { // TODO deveria ser um union??
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

char* build_scanf(char* type, char* id);

char* build_printf(char* str, char* type, char* id);
 
void freeNode(s_node *);

s_node * createNode(char *);

char* concat(int count, ...);

void remove_end_character(char* str);

#endif