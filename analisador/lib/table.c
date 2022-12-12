#include <stdio.h>
#include <string.h>

#include "table.h"
#include "util.h"

unsigned int hash(char* s0) {
    unsigned int index = 0;
    char* s;

    // nota: quando *s='\0' cujo valor inteiro é 0, a condição do for loop é falsa
    for( s = s0; *s; s++) {
        index = index * 65599  + *s;
    }
    return index;
}

t_container* Container( char* key, void* binding, t_container *next) {
    t_container *c = checked_malloc(sizeof(*c));
    
    c->key = key;
    c->binding = binding;
    c->next = next;
    return c;
}

void insert(char* key, void* binding) {
    int index = hash(key) % SIZE;
    table[index] = Container(key, binding, table[index]); 
}

void* lookup(char* key) {
    int index = hash(key) % SIZE;
    t_container *c;
    for(c = table[index]; c; c->next) {
        if(strcmp(c->key, key) == 0) {
            return c->binding;
        }
    }
    return NULL;
}

void pop(char* key) {
    int index = hash(key) % SIZE;
    table[index] = table[index]->next;
}


