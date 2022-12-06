#ifndef H_NODE
#define H_NODE

/**
 * Tipos existentes na linguagem
*/
typedef enum e_primitive_type {string, number, boolean, map}; 

/**
 * Representa um nó na árvore de derivação, 
 * com informações relevantes sobre os terminais e não-terminais
*/
typedef struct node {
    /* Geração do código alvo (C simplificado?) */
    char* target_code;

    /* Tipo do nó (se existir) */
    e_primitive_type type;

    /* Identificador (caso de variáveis e funções) */
    char* id;

    /* Valor da variável */


    /* Escopo */


    /* Valor de returno (no caso de uma função) */
    e_primitive_type return_value;

    /* Linha onde aconteceu a produção */
    int line;

} s_node;

 
void freeRecord(s_node *);

s_node * createRecord(char *, char *);

#endif