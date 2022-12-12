#include "potrex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeNode(s_node * r){
  if (r) {
    if (!r->target_code) free(r->target_code);
    free(r);
  }
}

s_node * createNode(char * c1){
  s_node * r = (s_node*) malloc(sizeof(s_node));

  if (!r) {
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }

  r->target_code = strdup(c1);

  return r;
}


char* concat(int count, ...){

  va_list lens;
  int len = 0;

  va_start(lens, count);

  for(int j=0; j<count; j++){

    len += strlen(va_arg(lens, char*));
  }

  /* +1 por causa do \0 para o fim da string */
  char* str = (char*) calloc(len + 1, sizeof(char));

  va_list concat;
  va_start(concat, count);

  for(int j=0; j<count; j++){
    strcat(str, va_arg(concat, char*));
  }

  return str;
}

s_stack* create_stack(){
  s_stack* stack = (s_stack*) malloc(sizeof(s_stack));
  stack->scopes = malloc(sizeof(s_scope));
  stack->size = 0;

  return stack;
}

void add_scope_to_stack(s_stack* stack, s_scope* scope){
  stack->scopes = (s_scope*) realloc(stack->scopes, sizeof(s_scope) * (stack->size + 1));
  stack->scopes[stack->size] = *(scope);
  stack->size += 1;
}

int remove_scope_from_stack(s_stack* stack, s_scope* scope){
    if(stack->size > 0) {
      stack->scopes = realloc(stack->scopes, sizeof(s_scope) * (stack->size - 1));
      stack->size -= 1;

      return 0;
    } 
    
    return -1;
}

int scope_contains(s_stack* stack, s_block_element* element){
    return 0;
}

void add_element_to_scope(s_scope* scope, s_block_element* element){

}

void remove_element_from_scope(s_scope* scope, s_block_element* element){

}

