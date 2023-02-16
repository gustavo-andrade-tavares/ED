#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main(void){
    int n, t;
    char resp;
    ABB *A;
    A = criar();

    while(resp != '4'){
        printf("[1] inserir.\n");
        printf("[2] imprimir.\n");
        printf("[3] apagar.\n");
        printf("[4] sair.\n");
        printf("[5] verifica se a arvore eh cheia.\n");
        printf("[6] quantidade de nos na arvore.\n");
        printf("[7] soma dos valores de todos os nos.\n");
        printf("Opcao escolhida: ");
        scanf("%s", &resp);

        if(resp == '1'){
            printf("Digite um numero: ");
            scanf("%d", &n);

            t = inserir(&A->raiz, &n);
            if(t == 0)
                printf("erro.\n");
            else
                printf("Inserido.\n\n\n");
        }

        else if(resp == '2'){
            pre_ordem(A->raiz);
            printf("Listagem completa.\n\n\n");
        }

        else if(resp == '3'){
            Finalizar(A->raiz);
            printf("Arvore apagada.\n\n\n");
        }

        else if(resp == '4'){
            printf("Saindo.\n\n\n");
        }

        else if(resp == '5'){
            if(Eh_Cheia(A->raiz))
                printf("A arvore eh cheia.\n\n\n");
            else
                printf("A arvore nao eh cheia.\n\n\n");
        }

        else if(resp == '6'){
            t = conta_no(A->raiz);
            printf("Ha %d nos na arvore.\n\n\n", t);
        }

        else if(resp == '7'){
            t = soma_valor_dos_nos(A->raiz);
            printf("A soma de todos os elementos da arvore eh %d.\n\n\n", t);
        }

        else
            printf("Entrada invalida. Digite novamente.\n\n\n");
    }

    return(0);
}
