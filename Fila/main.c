
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
    Fila F1, F2;
    Cria(&F1);
    Cria(&F2);

    printf("Digite os elementos da fila F1 ou digite -1 para sair: \n");
    scanf("%d", &x);
    while(x != -1) {
        Entra(&F1, &x, &erro);
        scanf("%d", &x);
    }

    printf("Digite os elementos da fila F2 ou digite -1 para sair: \n");
    scanf("%d", &x);
    while(x != -1) {
        Entra(&F2, &x, &erro);
        scanf("%d", &x);
    }
    printf("Fila 1: ");
    imprimir(F1);

    printf("Fila 2: ");
    imprimir(F2);
    /*
    printf("O primeiro elemento da fila 1 foi recuperado.\n");
    Sai(&F1, &x, &erro);
    printf("Agora a fila 1 eh: \n");
    imprimir(F1); */

    Verifica_Tamanho(&F1,&F2);

    system("pause");
    return(0);
}

