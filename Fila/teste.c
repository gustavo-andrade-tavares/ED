#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
void imprimir(Fila F) {
    elem x;
    int erro;
    while(!EstaVazia(&F)) {
        Sai(&F, &x, &erro);
        printf("%d", x);
    }
    printf("\n");
}

int main(void) {
    elem x;
    int erro;
    Fila F;

    Cria(&F);
    printf("Digite os elementos da fila F ou digite -1 para sair: \n");
    scanf("%d", &x);
    while(x != -1) {
        Entra(&F, &x, &erro);
        scanf("%d", &x);
    }

    printf("Fila: ");
    imprimir(F);
}
