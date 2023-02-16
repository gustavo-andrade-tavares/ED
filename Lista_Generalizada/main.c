#include <stdio.h>
#include <stdlib.h>
#include "Lista_Generalizada.h"

int main(void){
    char resp;
    int tipo, t;
    Lista_Gen *L;
    L = Cria();

    while(resp != 's'){
        printf("[a] Inserir elemento.\n");
        printf("[b] Imprimir lista.\n");
        printf("[c] Apagar lista.\n");
        printf("[s] Sair.\n");
        printf("Opcao escolhida: ");
        scanf("%s", &resp);

        if(resp == 'a'){
            printf("Digite o tipo do elemento, 0 para atomo e 1 para sublista: ");
            scanf("%d", &tipo);

            t = Inserir_el(L, &tipo);
            if(t == 0)
                printf("Elemento inserido.\n\n\n");
            else
                printf("Erro.\n\n\n");
        }

        else if(resp == 'b'){
            Imprimir(L);
            printf("\nListagem completa.\n\n\n");
        }

        else if(resp == 'c'){
            Apagar(L);
            printf("Lista apagada.\n\n\n");
        }

        else if(resp == 's')
            printf("Saindo do programa.\n\n\n");

        else
            printf("Entrada invalida. Digite novamente.\n\n\n");
    }
    return(0);
}
