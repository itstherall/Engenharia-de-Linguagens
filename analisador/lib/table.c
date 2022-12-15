#include "table.h"

t_container* Container( char* key, void* binding, t_container *next) {
    t_container *c = malloc(sizeof(*c)); // TODO checked malloc
    
    c->key = key;
    c->binding = binding;
    c->next = next;
    return c;
}

void S_insert(char* key, t_symbol* binding) {
    // insere no início da tabela
    S_table = Container(key, binding, S_table);
}

t_symbol* S_lookup(char* key) {
    
    t_container* current = S_table;
    while(current != NULL) {
        if(strcmp(key, current->key) == 0) {
            return current->binding;
        }
        current = current->next;
    }
    return NULL;
}

void S_remove(char* key) {
    
    if(strcmp(key, S_table->key) == 0) {
        t_container* removed = S_table;
        S_table = S_table->next;
        free(removed);
    } else {
        
        t_container* current = S_table->next;
        t_container* prev = S_table;
        while(current != NULL) {
            if(strcmp(key, current->key) == 0) {
                t_container* removed = current;
                prev->next = current->next;
                free(removed);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

void printTable() {
    printf("\n\n***** Imprimindo tabela de símbolos *****\n\n");

    if(S_table == NULL) {
        printf("tabela vazia");
    } else {

        t_container* current = S_table;
        while(current != NULL) {
            printf("key: %s id: %s\n", current->key, current->binding->id);
            current = current->next;
        } 
    
    }

    printf("\n\n***** FIM tabela de símbolos *****\n\n");
}

// int main (int argc, char **argv) {

//     t_symbol* s = (t_symbol*) malloc(sizeof(*s));
//     s->id = "a";
//     double v = 10;
//     s->value = &v;    
//     e_primitive_type e = number;
//     s->type = e;

//     S_insert("f1@a", s);

//     t_symbol* s2 = (t_symbol*) malloc(sizeof(*s2));
//     s2->id = "b";
//     v = 12;
//     s2->value = &v;    
//     s2->type = e;

//     S_insert("f2@b", s2);

//     t_symbol* s3 = (t_symbol*) malloc(sizeof(*s3));
//     s3->id = "c";
//     v = 14;
//     s3->value = &v;    
    
//     s3->type = e;

//     S_insert("f3@c", s3);

//     printTable();

//     printf("resultado da busca por f2@b: %s", S_lookup("f2@b")->id);

//     S_remove("f1@a");

//     printTable();

//     free(s);
//     free(s2);
//     free(s3);


//     return 0;
// }

