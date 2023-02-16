#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_ordenada.h"

int main(void){
    char name[30], resposta;
    int t;
    Lista_Ord *L;
    L = Cria();

    while(resposta != '5'){
        printf("[1] Inserir cadastro.\n");
        printf("[2] Imprimir lista.\n");
        printf("[3] Remover cadastro.\n");
        printf("[4] Apagar lista.\n");
        printf("[5] Sair.\n");
        printf("Opcao escolhida: ");
        scanf("%s", &resposta);

        if(resposta == '1'){
            printf("Digite o nome: ");
            fflush(stdin);
            gets(name);

            t = Inserir(L, name);
            if(t == 1)
                printf("Erro.\n\n\n");
            else
                printf("Cadastro realizado.\n\n\n");
        }

        else if(resposta == '2'){
            Imprimir(L);
            printf("\nListagem completa.\n\n\n");
        }

        else if(resposta == '3'){
            printf("Digite o nome para remover: ");
            fflush(stdin);
            gets(name);

            t = Remover(L, name);
            if(t == 0)
                printf("Cadastro removido.\n\n\n");
            else if(t == 1)
                printf("Lista vazia.\n\n\n");
            else
                printf("Cadastro inexistente.\n\n\n");
        }

        else if(resposta == '4'){
            Apagar(L);
            printf("Lista apagada.\n\n\n");
        }

        else if(resposta == '5'){
            printf("Saindo.\n\n\n");
        }

        else{
            printf("Entrada invalida. Digite novamente.\n");
        }
    }
    return(0);
}
