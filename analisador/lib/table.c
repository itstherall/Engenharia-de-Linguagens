#include "table.h"

t_container* tabela; // lista ligada

void create_table() {
    tabela = NULL;
}


t_container* Container( char* key, void* binding, t_container *next) {
    t_container *c = malloc(sizeof(*c)); // TODO checked malloc
    
    c->key = key;
    c->binding = binding;
    c->next = next;
    return c;
}

void S_insert(char* key, t_symbol* binding) {
    // insere no início da tabela
    tabela = Container(key, binding, tabela);
}

t_symbol* S_lookup(char* key) {
    
    t_container* current = tabela;
    while(current != NULL) {
        //printf("searching %s... found %s\n", key, current->key);
        
        if(strcmp(key, current->key) == 0) {
            //printf("found %s\n", current->key);
            return current->binding;
        }
        current = current->next;
    }
    return NULL;
}

t_container* S_remove(char* key) {
    
    if(strcmp(key, tabela->key) == 0) {
        t_container* removed = tabela;
        tabela = tabela->next;
        free(removed);
        
        return tabela;

    } else {
        
        t_container* current = tabela->next;
        t_container* prev = tabela;
        while(current != NULL) {
            if(strcmp(key, current->key) == 0) {
                t_container* removed = current;
                prev->next = current->next;
                free(removed);
                
                return prev->next;
            }
            prev = current;
            current = current->next;
        }
    }

    return NULL;
}

void S_remove_all(char* scope) {
    int size = 0;
    char* it = scope;
    
    //printf("\nremoving all variables/functions from scope %s\n", scope);

    // nota: quando *it='\0', cujo valor inteiro é 0, a condição do for loop é falsa
    while(*it) {
        size++;
        it++;
    } 
        
    t_container* current = tabela;
    while(current != NULL) {
        //printf("comparando %s com %s: %d\n", current->key, scope, strncmp(current->key, scope, size));
        if(strncmp(current->key, scope, size) == 0) {
            current = S_remove(current->key);
            //printTable();
        } else {
            current = current->next;
        }
    }
    
}


void printTable() {
    printf("\n***** Imprimindo tabela de símbolos *****\n");

    if(tabela == NULL) {
        printf("tabela vazia");
    } else {

        t_container* current = tabela;
        while(current != NULL) {
            if(current->next == NULL) {
                printf("key: %s id: %s next: null\n", current->key, current->binding->id);
            } else {
                printf("key: %s id: %s next: %s\n", current->key, current->binding->id, current->next->key);
            }
            current = current->next;
        } 
    
    }

    printf("\n***** FIM tabela de símbolos *****\n");
}

// int main (int argc, char **argv) {

//     t_symbol* s = (t_symbol*) malloc(sizeof(*s));
//     s->id = "a";
//     double v = 10;
//     s->value = &v;    
//     e_primitive_type e = number;
//     s->type = e;

//     S_insert("f1@a", s);

//     t_symbol* s1 = (t_symbol*) malloc(sizeof(*s));
//     s1->id = "a";
//     v = 100;
//     s1->value = &v;    
//     s1->type = e;

//     S_insert("f3@a", s1);

//     t_symbol* s2 = (t_symbol*) malloc(sizeof(*s2));
//     s2->id = "b";
//     v = 12;
//     s2->value = &v;    
//     s2->type = e;

//     S_insert("f1@b", s2);

//     t_symbol* s3 = (t_symbol*) malloc(sizeof(*s3));
//     s3->id = "c";
//     v = 14;
//     s3->value = &v;    
    
//     s3->type = e;

//     S_insert("f3@c", s3);

//     t_symbol* s4 = (t_symbol*) malloc(sizeof(*s3));
//     s4->id = "d";
//     v = 17;
//     s4->value = &v;    
    
//     s4->type = e;

//     S_insert("f3@d", s4);

//     printTable();

//     t_symbol* f = S_lookup("f1@b");
//     if(f != NULL) {
//         printf("resultado da busca por f1@b: %s\n", f->id);
//     } else {
//         printf("símbolo f1@b não encontrado\n");
//     }

//     //S_remove("f1@a");
//     S_remove_all("f3");

//     printTable();

//     free(s);
//     free(s1);
//     free(s2);
//     free(s3);
//     free(s4);

//     return 0;
// }

