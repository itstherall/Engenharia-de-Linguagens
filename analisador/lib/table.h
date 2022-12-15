#ifndef H_TABLE
#define H_TABLE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "potrex.h"
//#include "util.h"


/* tabela de símbolos **
 * tabela de símbolos implementada como lista ligada.
 */

typedef struct table_symbol
{
    char* id; // TODO precisa? 
    e_primitive_type type;
    void* value; // TODO deveria ser um union dos tipos do c ou usa um cast?

} t_symbol;

typedef struct table_container
{
    char* key; // scopeName ++ symbol ++ id, onde symbol é @ para variáveis e # para funções
    t_symbol* binding;
    struct table_container* next;
} t_container;

t_container* tabela; // lista ligada

void create_table();

/* construtor de containers */
t_container* Container( char* key, void* binding, t_container* next);

/* Entra key->symbol na tabela
 * key = subprograma ++ nome
 * 
 */
void S_insert(char* key, t_symbol* binding);

/* Veja o valor de key na tabela */
t_symbol* S_lookup(char* key);

/* remove um símbolo da tabela e retorna posição do nó removido
 */
t_container* S_remove(char* key);

/* remove todos os símbolos definidos em um mesmo escopo da tabela
 */
void S_remove_all(char* scope);

void printTable();

#endif
