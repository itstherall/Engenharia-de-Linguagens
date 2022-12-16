#include "potrex.h"

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

char* build_scanf(char* type, char* id){
  char* read = malloc(sizeof(char)*1000);
  sprintf(read, "scanf(");

  if(strcmp(type, "double") == 0){
    strcat(read, "\"%lf\"");
  }
  if(strcmp(type, "char*") == 0){
    strcat(read, "\"%s\"");
  }
  if(strcmp(type, "int") == 0){
    strcat(read, "\"%d\"");
  }

  strcat(read, ", &");
  strcat(read, id);
  strcat(read, ")");

  return read;
}

char* build_printf(char* str, char* type, char* id){
  char* print = malloc(sizeof(char)*10000);
  
  //print("assim")
  //print("assim", number var)
  //print(number var)
  if(str != NULL){
    sprintf(print, "%s", str);
  }


  // "My str %s", var

  if(type != NULL){
    // remove aspas do fim print
    char* end = print;
    while(*(end + 1) != '\0') {
    end++;
    }
    *end = '\0';

    if(strcmp(type, "double") == 0){
      strcat(print, "%lf\"");
    }
    if(strcmp(type, "char*") == 0){
      strcat(print, "%s\"");
    }
    if(strcmp(type, "int") == 0){
      strcat(print, "%d\"");
    }

    strcat(print, ", ");
    strcat(print, id);
  }

  return print;
}


void remove_end_character(char* str){
    char* end = str;
    while(*(end + 1) != '\0') {
    end++;
    }
    *end = '\0';
}


