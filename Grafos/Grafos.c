#include <stdio.h>
#include <stdlib.h>
#include "Grafos.h"

Grafo* Criar_grafo(int *N, int *direcao, int *erro){
    if(*N > MaxNumVertices){
        *erro = 1;
        return(NULL);
    }
    Grafo *G = (Grafo*) malloc(sizeof(Grafo));
    if(G == NULL){
        *erro = 1;
        return(NULL);
    }

    else{
        G->NumVertices = *N;
        G->direcionado = *direcao;
        for(int i = 0; i<G->NumVertices; i++)
            for(int j = 0; j<G->NumVertices; j++)
                G->m[i][j] = SemArestas;
        *erro = 0;
        return(G);
    }
}

void Finalizar(Grafo *G){
    if(G != NULL)
        free(G);
}

void Esvaziar(Grafo *G){
    for(int i = 0; i<G->NumVertices; i++)
            for(int j = 0; j<G->NumVertices; j++)
                G->m[i][j] = SemArestas;
}

void Inserir_Aresta(Grafo *G, int *V1, int *V2, elem *P, int *erro){
    if((*V1 >= G->NumVertices) || (*V2 >= G->NumVertices))
        *erro = 1;
    else{
        if(G->m[*V1][*V2] != SemArestas)
            *erro = 1;
        else{
        G->m[*V1][*V2] = *P;
        if(G->direcionado == 0)
            G->m[*V2][*V1] = *P; // se grafo nao direcionado
        *erro = 0;
        }
    }
}

elem Retirar_aresta(Grafo *G, int *V1, int *V2, int *erro){
    if((*V1 >= G->NumVertices) || (*V2 >= G->NumVertices)){
        *erro = 1;
        return(SemArestas);
    }

    else{
        if(G->m[*V1][*V2] == SemArestas){
            *erro = 1;
            return(SemArestas);
        }
        else{
            elem peso = G->m[*V1][*V2];
            G->m[*V1][*V2] = SemArestas;
            if(G->direcionado == 0)
                G->m[*V2][*V1] = SemArestas;
            *erro = 0;
            return(peso);
        }
    }
}

int Existe_Aresta(Grafo *G, int *V1, int *V2, int *erro){
    if((*V1 >= G->NumVertices) || (*V2 >= G->NumVertices)){
        *erro = 1;
        return(SemArestas);
    }

    else{
        *erro = 0;
        if(G->m[*V1][*V2] == SemArestas)
            return(0);
        else
            return(1);

        //return(G->m[*V1][*V2] != SemArestas);
    }
}

void Imprimir_matriz_adj(Grafo *G){
    int i, j;
    for(i = 0; i < G->NumVertices; i++){
        //printf("%d ", i);
        for(j = 0; j < G->NumVertices; j++){
            printf("%d ", G->m[i][j]);
        }
        printf("\n");
    }
}
