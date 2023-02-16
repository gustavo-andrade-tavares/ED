#include <stdio.h>
#include <stdlib.h>
#include "Grafos_buscas.h"

int main(void){
    int qtd_vertices, drc, v1, v2, peso, erro;
    char resp;
    Grafo *G;

    printf("Informe o numero de vertices do grafo: ");
    scanf("%d", &qtd_vertices);

    printf("O grafo eh direcionado? 0 para nao direcionado e 1 para direcionado: ");
    scanf("%d", &drc);

    G = criar(&qtd_vertices, &drc, &erro);
    if(erro)
        printf("Erro. Falta de memoria.\n\n\n");
    else
        printf("Grafo criado com sucesso.\n\n\n");

    while(resp != '4'){
        printf("[1] Inserir aresta.\n");
        printf("[2] Imprimir grafo de lista de adjacencias.\n");
        printf("[3] Liberar memoria.\n");
        printf("[4] Sair.\n");
        printf("Opcao escolhida: ");
        scanf("%s", &resp);

        if(resp == '1'){
            printf("Digite o vertice 1: ");
            scanf("%d", &v1);

            printf("Digite o vertice 2: ");
            scanf("%d", &v2);

            printf("Digite o peso: ");
            scanf("%d", &peso);

            inserir_aresta(G, &v1, &v2, &peso, &erro);
            if(erro)
                printf("Erro. Vertice inexistente.\n\n\n");
            else
                printf("Aresta inserida  com sucesso.\n\n\n");
        }

        else if(resp == '2'){
            printf("Impressao do grafo: \n");
            imprimir(G);
        }

        else if(resp == '3'){
            liberar_memoria(G);
            printf("Grafo apagado.\n\n\n");
        }

        else if(resp == '4'){
            printf("Saindo.\n\n\n");
        }

        else{
            printf("Entrada invalida. Digite novamente.\n\n\n");
        }
    }
    return(0);
}
