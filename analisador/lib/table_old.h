/* tabela de símbolos **
 * Tabela hash genérica com encadeamento externo. 
 * Baseado no Programa 5.2 (pg 106) do livro 
 * "Modern Compiler Implementation in C - Andrew W. Appel"
 */

typedef struct container
{
    char* key;
    void* binding;
    t_container *next;
} t_container;

// SIZE deve ser primo
#define SIZE 109

/* A tabela de símbolos é uma hash table implementada como um array de ponteiros para containers */
t_container *table[SIZE];

/* Função hash simplificada. Converte um string num índice. */
unsigned int hash(char* s0);

/* construtor */
t_container* Container( char* key, void* binding, t_container *next);

/* Entra key->symbol na tabela
 * key = subprograma ++ nome
 * bindings que possuem uma mesma chave são inseridos como se fosse uma pilha.
 */
void insert(char* key, void* binding);

/* Veja o valor de key na tabela */
void* lookup(char* key);

/* pop o binding mais recente e retorne sua chave. 
 * Isso pode expor outro binding para a mesma chave.
 * Feito no fim de um escopo para restaurar o escopo anterior.
 */
void pop(char* key);
