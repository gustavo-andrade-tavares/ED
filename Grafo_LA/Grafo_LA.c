#include <stdio.h>
#include <stdlib.h>
#include "Grafo_LA.h"

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
        for(int i = 0; i < G->NumVertices; i++){
            G->Adj[i].inicio = NULL;
            G->Adj[i].fim = NULL;
            G->Adj[i].grau = 0;
        }
        *erro = 0;
        return(G);
    }
}

int Inserir_Aresta(Grafo *G, int *pos_i, int *vertice, int *peso_aresta){
    if(*pos_i > MaxNumVertices)
        return(1);
    else{
        no_aresta *v = (no_aresta*) malloc(no_aresta);
        if(v == NULL)
            return(1);
        v->V = *vertice;
        v->Peso = *peso_aresta;
        v->prox = NULL;

        if(G->Adj[*pos_i].inicio == NULL){
            G->Adj[*pos_i].inicio = v;
            G->Adj[*pos_i].fim = v;
            G->Adj[*pos_i].grau++;
        }

        else {
            G->Adj[*pos_i].fim->prox = v;
            G->Adj[*pos_i].fim = v;
            G->Adj[*pos_i].grau++;
        }
    }
    return(0);
}

int Existe_Aresta(Grafo *G, int *pos_i, int *vertice){
    no_aresta *aux;
    aux = G->Adj[*pos_i].inicio;
    while(aux != NULL){
        if(aux->V == *vertice)
            return(0);
        else
            aux = aux->prox
    }
    return(1);
}

int Retirar_Aresta(Grafo *G, int *pos_i, int *vertice){
    // Caso 1: somente uma aresta
    if((G->Adj[*pos_i].inicio->V == *vertice) && (G->Adj[*pos_i].fim->V == *vertice)){
        no_aresta *aux;
        aux = G->Adj[*pos_i].inicio;
        G->Adj[*pos_i].inicio = NULL;
        G->Adj[*pos_i].fim = NULL;
        free(aux);

        return(0);
    }

    // Caso 2: aresta no inicio
    else if(G->Adj[*pos_i].inicio->V == *vertice){
        no_aresta *aux;
        aux = G->Adj[*pos_i].inicio;
        G->Adj[*pos_i].inicio = G->Adj[*pos_i].inicio->prox;
        free(aux);

        return(0);
    }

    // Caso 3: aresta no final
    else if(G->Adj[*pos_i].fim->V == *vertice){
        no_aresta *aux, *e_a;
        aux = G->Adj[*pos_i].inicio;
        while(aux->prox != G->Adj[*pos_i].fim)
            aux = aux->prox;
        *e_a = G->Adj[*pos_i].fim;
        G->Adj[*pos_i].fim = aux;
        free(e_a);

        return(0);
    }

    // Caso 4: aresta no meio
    else {
        no_aresta *cursor1, *cursor2;
        cursor1 = G->Adj[*pos_i].inicio;
        cursor2 = G->Adj[*pos_i].inicio->prox;
        while(cursor2->V != *vertice){
            cursor1 = cursor1->prox;
            cursor2 = cursor2->prox;
        }
        cursor1->prox = cursor2->prox;
        free(cursor2);

        return(0);
    }
    return(1); // vertice inexistente
}

void Finalizar(Grafo *G){
    for(int i = 0; i < G->NumVertices; i++){
        no_aresta *e_a;
        e_a = G->Adj[i].inicio;
        while(e_a != NULL){
            G->Adj[i].inicio = G->Adj[i].inicio->prox;
            free(e_a);
            e_a = G->Adj[i].inicio;
        }
    }
    free(G);
}
