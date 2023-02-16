#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void Cria(Fila *F) {
    F->inicio = 0;
    F->fim = 0;
    F->total = 0;
}

int EstaVazia(Fila *F) {
    if(F->total == 0)
        return(1);
    else
        return(0);
}

int EstaCheia(Fila *F) {
    if(F->total == TamFila)
        return(1);
    else
        return(0);
}

void Entra(Fila *F, elem *x, int *erro) {
    if(EstaCheia(F))
        *erro = 1;
    else {
        F->itens[F->fim] = *x;
        if(F->fim == TamFila-1)
            F->fim = 0;
        else
            F->fim++;
        F->total++;
        *erro = 0;
    }
}

void Sai(Fila *F, elem *x, int *erro) {
    if(EstaVazia(F))
        *erro = 1;
    else {
        *x = F->itens[F->inicio];
        if(F->inicio == TamFila-1)
            F->inicio = 0;
        else
            F->inicio++;
        F->total--;
        *erro = 0;
    }
}

void Esvazia(Fila *F) {
    F->inicio = 0;
    F->fim = 0;
    F->total = 0;
}
