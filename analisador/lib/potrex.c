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
