#ifndef H_TABLE
#define H_TABLE

#include <stdio.h>
#include <string.h>

#include "table.h"
#include "potrex.h"


/* tabela de símbolos **
 * tabela de símbolos implementada como lista ligada.
 */

typedef struct table_container
{
    char* key; // scopeName ++ symbol ++ id, onde symbol é @ para variáveis e # para funções
    symbol* binding;
    t_container *next;
} t_container;

t_container *table; // TODO deve ser uma lista ligada, conferir

typedef struct symbol
{
    char* id; // TODO precisa? 
    e_primitive_type type;
    void* value; // TODO deveria ser um union dos tipos do c?

} s_symbol;

/* Entra key->symbol na tabela
 * key = subprograma ++ nome
 * 
 */
void insert(char* key, s_symbol binding);

/* Veja o valor de key na tabela */
s_symbol lookup(char* key);

/* remove um símbolo da tabela
 */
void remove(char* key);

#endif
