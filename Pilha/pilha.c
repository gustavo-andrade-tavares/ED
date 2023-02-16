#include "pilha.h"
#include <stdio.h>

void Create(Pilha *P) {
    P->topo = -1;
    P->total = 0;
    return;
}

void Empty(Pilha *P) {
    P->topo = -1;
    P->total = 0;
    return;
}

int IsEmpty(Pilha *P) {
    if(P->topo == -1)
        return(1);
    else return(0);
}

int IsFull(Pilha *P) {
    if(P->topo == TamPilha-1)
        return(1);
    else return(0);
}

void Push(Pilha *P, elem *x, int *erro) {
    if(!IsFull(P)) {
        P->topo++;
        P->itens[P->topo] = *x;
        P->total++;
        *erro = 0;
    }
    else *erro = 1;
    return;
}

void Pop(Pilha *P, elem *x, int *erro) {
    if(!IsEmpty(P)) {
        *x = P->itens[P->topo];
        P->topo--;
        P->total--;
        *erro = 0;
    }
    else *erro = 1;
    return;
}

elem Top(Pilha *P, int *erro) {
    if(!IsEmpty(P)) {
        *erro = 0;
        return(P->itens[P->topo]);
    }
    else {
        *erro = 1;
        return(-1);
    }
}

void Imprimir(Pilha *P) {
    elem x;
    int erro;
    Pilha aux;
    Create(&aux);

    printf("Os elementos da pilha são: \n");
    while(!IsEmpty(P)) {
        Pop(P, &x, &erro);
        printf("%.2f\n", x);
        Push(&aux, &x, &erro);
    }
    printf("\n");
    while(!IsEmpty(&aux)) {
        Pop(&aux,&x,&erro);
        Push(P, &x, &erro);
    }
}

int Iguais(Pilha P1, Pilha P2) {
    elem x1, x2;
    int erro1, erro2;

    while((!IsEmpty(&P1)) || (!IsEmpty(&P2))) {
        Pop(&P1, &x1, &erro1);
        Pop(&P2, &x2, &erro2);
        if((x1 != x2) || (erro1 != erro2)) {
            return(0);
        }
    }
    return(1);
}

void Inverter(Pilha *P) {
    elem x;
    int erro, i = -1, j;
    elem v[TamPilha];

    while(!IsEmpty(P)) {
        Pop(P, &x, &erro);
        i++;
        v[i] = x;
    }
    for (j = 0; j <= i; j++)
        Push(P, &v[j], &erro);
}

int Tamanho(Pilha *P) {
    return(P->total);
}

void Teste_de_Tamanho(Pilha *P1, Pilha *P2) {
    if((P1->total) > (P2->total))
        printf("\nA pilha P1 tem mais elementos que a pilha P2.\n");
    else if((P1->total) < (P2->total))
        printf("\nA pilha P1 tem menos elementos que a pilha P2.\n");
    else
        printf("As pilhas tem tamanhos iguais");
}

