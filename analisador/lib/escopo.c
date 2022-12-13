#include "escopo.h"


void create_scope_stack() {
    stack = (s_scope_stack*) malloc(sizeof(s_scope_stack));

    s_container* global = (s_container*) malloc(sizeof(s_container));
    global->name = "global";

    stack->scopes[0] = *global;
    stack->size = 1;
}


void push(s_container* scope){
    stack->scopes[stack->size] = *scope;
    stack->size++;
}

 
s_container* pop(){
    stack->size--;
    return &stack->scopes[stack->size];
}


s_container* top(int index) {
    if(index >= 0 && index < stack->size){
        return &stack->scopes[stack->size - index - 1];
    }
    else{
        printf("Acesso inexistente ao escopo!");
        exit(1);
    }
};