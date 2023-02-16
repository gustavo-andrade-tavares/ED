#include <stdio.h>
#include <stdlib.h>
#include "Lista_duplamente_enc.h"

int main(void){
    char letra;
    int t, resp = 0;
    Lista_D *L;
    L = Cria_Lista();

    while(resp != 5){
        printf("Escolha uma opcao: \n");
        printf("[1] Inserir letra.\n");
        printf("[2] Imprimir lista.\n");
        printf("[3] Imprimir lista em ordem inversa.\n");
        printf("[4] Apagar lista.\n");
        printf("[5] Sair.\n\n");
        printf("Resposta: ");
        scanf("%d", &resp);

        if(resp == 1){
            printf("Digite uma letra: ");
            scanf("%s", &letra);
            t = Inserir(L, &letra);
            if(t == 1)
                printf("Erro. Falta de memoria. \n\n\n");
            else
                printf("Letra inserida.\n\n\n");
        }

        else if(resp == 2){
            t = Imprimir(L);
            if(t == 0)
                printf("\nListagem completa.\n\n\n");
            else
                printf("Erro.\n\n\n");
        }

        else if(resp == 3){
            t = Imprimir_inv(L);
            if(t == 0)
                printf("\nListagem completa.\n\n\n");
            else
                printf("Erro.\n\n\n");
        }

        else if(resp == 4){
            t = Apagar_Lista(L);
            if(t == 0)
                printf("Lista apagada.\n\n\n");
            else
                printf("Erro.\n\n\n");
        }

        else if(resp == 5){
            printf("Saindo do programa.\n");
        }

        else{
            printf("Entrada invalida. Digite novamente.\n");
        }
    }
    return(0);
}
