#include <stdio.h>
#include <stdlib.h>
#include "Lista_duplamente_enc.h"

Lista_D* Cria_Lista(void){
    Lista_D *Laux = (Lista_D*) malloc(sizeof(Lista_D));
    if(Laux == NULL)
        return(NULL);
    Laux->inicio = NULL;
    Laux->fim = NULL;
    return(Laux);
}

int Inserir(Lista_D *L, elem *x){
    no *e = (no*) malloc(sizeof(no));
    if(e == NULL)
        return(1);
    e->item = *x;
    e->anterior = NULL;
    e->proximo = NULL;

    if(L->inicio == NULL){
        L->inicio = e;
        L->fim = e;
    }

    else{
        L->fim->proximo = e;
        e->anterior = L->fim;
        L->fim = e;
    }
    return(0);
}

int Imprimir(Lista_D *L){
    no *e_a;
    e_a = L->inicio;
    while(e_a != NULL){
        printf("%c ", e_a->item);
        e_a = e_a->proximo;
    }
    return(0);
}

int Imprimir_inv(Lista_D *L){
    no *e_a;
    e_a = L->fim;
    while(e_a != NULL){
        printf("%c ", e_a->item);
        e_a = e_a->anterior;
    }
    return(0);
}

int Apagar_Lista(Lista_D *L){
    no *e_a;
    e_a = L->inicio;
    while(e_a != NULL){
        L->inicio = L->inicio->proximo;
        free(e_a);
        e_a = L->inicio;
    }
    return(0);
}
