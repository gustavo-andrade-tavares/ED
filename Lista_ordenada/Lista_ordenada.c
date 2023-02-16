#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_ordenada.h"

Lista_Ord* Cria(void){
    Lista_Ord *Laux = (Lista_Ord*) malloc(sizeof(Lista_Ord));
    if(Laux == NULL)
        return(NULL);
    Laux->inicio = NULL;

    return(Laux);
}

int IsEmpty(Lista_Ord *L){
    if(L->inicio == NULL)
        return(1);
    return(0);
}

no* Busca(Lista_Ord *L, char *x){
    no *aux;
    int teste;
    aux = L->inicio;
    while(aux != NULL){
        teste = strcmp(aux->nome, x);
        if(teste == 0)
            return(aux);
        else
            aux = aux->prox;
    }
    return(NULL);
}

int Inserir(Lista_Ord *L, char *x){
    no *u = (no*) malloc(sizeof(no));
    if(u == NULL)
        return(1);
    strcpy(u->nome, x);
    u->prox = NULL;

    // Caso 1: Lista vazia.
    if(L->inicio == NULL){
        L->inicio = u;
    }

    // Caso 2: x < primeiro.
    else if(strcmp(u->nome, L->inicio->nome) < 0){
        u->prox = L->inicio;
        L->inicio = u;
    }

    // Caso 3: x > primeiro.
    else {
        no *anterior, *proximo;
        anterior = L->inicio;
        proximo = L->inicio->prox;
        if(proximo == NULL){
            anterior->prox = u;
        }
        while(proximo != NULL){
            if((strcmp(anterior->nome, u->nome) < 0) && (strcmp(proximo->nome, u->nome) > 0)){
                u->prox = proximo;
                anterior->prox = u;
                break;
            }
            else {
                anterior = anterior->prox;
                proximo = proximo->prox;
                if((anterior != NULL) && (proximo == NULL)){
                    anterior->prox = u;
                    break;
                }
                else
                    continue;
            }
        }
    }
    return(0);
}

int Remover(Lista_Ord *L, char *x){
    // Caso 1: Lista vazia.
    if(IsEmpty(L))
        return(1);

    // Caso 2: x < primeiro.
    else if(strcmp(x, L->inicio->nome) < 0)
        return(2);

    // Caso 3: x == primeiro.
    else if(strcmp(x, L->inicio->nome) == 0){
        no *aux;
        aux = L->inicio;
        L->inicio = L->inicio->prox;
        free(aux);
        return(0);
    }

    // Caso 4: x > primeiro.
    else {
        no *anterior, *proximo;
        anterior = L->inicio;
        proximo = L->inicio->prox;
        if(proximo == NULL)
            return(2);
        while(proximo != NULL){
            if(!strcmp(proximo->nome, x)){
                anterior->prox = proximo->prox;
                free(proximo);
                return(0);
            }
            else{
                anterior = anterior->prox;
                proximo = proximo->prox;
            }
        }
        return(2);
    }
}

void Imprimir(Lista_Ord *L){
    no *e_a;
    e_a = L->inicio;
    while(e_a != NULL){
        printf("%s ", e_a->nome);
        e_a = e_a->prox;
    }
}

void Apagar(Lista_Ord *L){
    no *e_a;
    e_a = L->inicio;
    while(e_a != NULL){
        L->inicio = L->inicio->prox;
        free(e_a);
        e_a = e_a->prox;
    }
}
