#include "escopo.h"


void create_scope_stack() {
    stack = (s_scope_stack*) malloc(sizeof(s_scope_stack));
    /*Checando se a alocação ocorreu corretamente*/
    if(!stack){
        printf("Alocação não foi feita! Memória esgotada!\n");
        exit(1);
    }

    s_container* global = (s_container*) malloc(sizeof(s_container));
    /*Checando se a alocação ocorreu corretamente*/
    if(!global){
        printf("Alocação não foi feita! Memória esgotada!\n");
        exit(1);
    }
    global->name = "global";

    stack->scopes[0] = *global;
    stack->size = 1;
}


s_container* create_container(){
    s_container* container = (s_container*) malloc(sizeof(s_container));
    /*Checando se a alocação ocorreu corretamente*/
    if(!container){
        printf("Alocação não foi feita! Memória esgotada!\n");
        exit(1);
    }

    /*Aqui podemos colocar para passar o nome do escopo logo como parametro
    * depois só linkar
    */
   
    container->name = "tester";
    return container;
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

void printEscope() {
    printf("\n\n***** Imprimindo pilha de escopo *****\n\n");

    for(int i = 0; i < stack->size; i++) {
        printf("posicao: %d escopo: %s", i, stack->scopes[i].name);
    }

    printf("\n\n***** FIM pilha de escopo *****\n\n");
}

