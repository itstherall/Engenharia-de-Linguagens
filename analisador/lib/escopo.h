#ifndef H_ESCOPO
#define H_ESCOPO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include "util.h"


typedef struct scope_container {
    
    char* name;

} s_container;

typedef struct scope_stack {
    s_container scopes[1000];
    int size;
} s_scope_stack;


/*GLOBAIS*/
s_scope_stack* stack;

/* escopo **
 * Escopo implementado como uma pilha única com uma função top especial
 */
void create_scope_stack();

s_container* create_container();

void push(s_container *scope);

 
s_container* pop();

/* */
s_container* top(int index);

void printEscope();

#endif