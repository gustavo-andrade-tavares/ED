#include "lista.h"

Lista* Criar(void) {
    Lista *Laux = (Lista*) malloc(sizeof(Lista));
    if(Laux==NULL)
        return(NULL);
    Laux->inicio = NULL;
    Laux->fim = NULL;
    return(Laux);
}

void Inserir(Lista *L, elem *x, int *erro) {
    no *p;
    p = (no*) malloc(sizeof(no));
    if(p == NULL) {
        *erro = 1;
        return;
    }
    p->info = *x;
    p->prox = NULL;
    if(L->inicio==NULL) {
        L->inicio = p;
        L->fim = p;
    }
    else {
        L->fim->prox = p;
        L->fim = p;
    }
    *erro = 0;
}

void Finalizar(Lista *L) {
    no *p;
    p = L->inicio;
    while(p!=NULL) {
        L->inicio = L->inicio->prox;
        free(p);
        p = L->inicio;
    }
    L->fim = NULL;
    free(L);
}

int Esta_na_Lista(Lista *L, elem *x) {
    no *p;
    p = L->inicio;
    while((p != NULL) && (p->info != *x)
          p = p->prox;
    if(p != NULL)
        return(1);
    else
        return(0);


}

int Tamanho(Lista *L) {
    int contador = 0;
    no *p = L->inicio;
    while(p != NULL) {
        contador++;
        p = p->prox;
    }
    return(contador);
}

int Tamanho_rec(no *P) {
    if(p == NULL)
        return(0);
    else
        return(1+Tamanho_rec(p->prox));
}

void Eliminar(Lista *L, elem *x, int *erro) {
    no *p, *anterior;
    int teste_achou = 0;

    p = L->inicio;
    anterior = NULL;
    while((p != NULL) && (!teste_achou)) {
        if(p->info != *x) {
            anterior = p;
            p = p->prox;
        }
        else {
            // se x esta no inicio da lista
            if(p == L->inicio) {
                L->inicio = L->inicio->prox;
                if(L->inicio == NULL)
                    L->fim = NULL;
                free(p);
                teste_achou = 1;
            }
            // se x esta no fim da lista
            else if(p == L->fim) {
                L->fim = anterior;
                L->fim->prox = NULL;
                free(p);
                teste_achou = 1;
            }
            // se x esta no meio da lista
            else {
                anterior->prox = p->prox;
            }
            free(p);
            teste_achou = 1;
        }
    }
    *erro = !teste_achou;
}
