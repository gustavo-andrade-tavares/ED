#include <stdio.h>
#include <stdlib.h>
#include "Grafos_buscas.h"
#include "fila.h"

/*declaração da estrutura de dados
*/

typedef struct no_aresta {
        int v;
        elem peso;
        int cor; //nessa versão, a cor ficará no nó de cabeçalho
        struct no_aresta *prox;
} no_aresta;

typedef struct {
        no_aresta *inicio, *fim;
} no_vertice;

struct grafo{
        no_vertice Adj[MaxNumVertices];
        int NumVertices, direcionado;
};


/*inicializando grafo com nós de cabeçalho apenas
*/
Grafo* criar(int *NumVertices, int *direcionado, int *erro) {
     if (*NumVertices>MaxNumVertices) {
        *erro=1;
        return(NULL);
     }
     else {
          Grafo *G=(Grafo*) malloc(sizeof(Grafo));
          if (!G)
            *erro=1;
          else {
            *erro=0;
            G->NumVertices=*NumVertices;
            G->direcionado=*direcionado;
            int i;
            for (i=0; i<G->NumVertices; i++) {
              G->Adj[i].inicio=(no_aresta*) malloc(sizeof(no_aresta));
              G->Adj[i].inicio->peso=0; //usado para armazenar grau do vértice
              G->Adj[i].inicio->cor=0; //usado para armazenar a cor de um vértice, inicializado incolor/branco
              G->Adj[i].inicio->prox=NULL;
              G->Adj[i].fim=G->Adj[i].inicio;
            }
          }
          return(G);
     }
}

/*função que insere uma aresta de peso P entre V1 e V2 no grafo
*/
void inserir_aresta(Grafo *G, int *V1, int *V2, elem *P, int *erro) {
     if ((*V1>=G->NumVertices) || (*V2>=G->NumVertices))
        *erro=1;
     else {
          *erro=0;
          G->Adj[*V1].inicio->peso++;
          G->Adj[*V1].fim->prox=(no_aresta*) malloc(sizeof(no_aresta));
          G->Adj[*V1].fim=G->Adj[*V1].fim->prox;
          G->Adj[*V1].fim->v=*V2;
          G->Adj[*V1].fim->peso=*P;
          G->Adj[*V1].fim->prox=NULL;

          if (G->direcionado==0) {
            G->Adj[*V2].inicio->peso++;
            G->Adj[*V2].fim->prox=(no_aresta*) malloc(sizeof(no_aresta));
            G->Adj[*V2].fim=G->Adj[*V2].fim->prox;
            G->Adj[*V2].fim->v=*V1;
            G->Adj[*V2].fim->peso=*P;
            G->Adj[*V2].fim->prox=NULL;
          }
     }
}

/*função que verifica se uma aresta existe
*/
int existe_aresta(Grafo *G, int *V1, int *V2, int *erro) {
    if ((*V1>=G->NumVertices) || (*V2>=G->NumVertices)) {
       *erro=1;
       return 0;
    }
    else {
         *erro=0;
         int encontrou=0;
         no_aresta *aux=G->Adj[*V1].inicio->prox;
         while ((aux!=NULL) && (!encontrou))
               if (aux->v==*V2)
                  encontrou=1;
               else aux=aux->prox;
         return(encontrou);
    }
}

/*função que retira uma aresta do grafo, retornando seu peso
*/
void retirar_aresta(Grafo *G, int *V1, int *V2, elem *P, int *erro) {
    if ((*V1>=G->NumVertices) || (*V2>=G->NumVertices))
       *erro=1;
    else {
         *erro=0;
         int encontrou=0;
         no_aresta *ant=G->Adj[*V1].inicio;
         no_aresta *aux=ant->prox;
         while ((aux!=NULL) && (!encontrou)) {
               if (aux->v==*V2) {
                  G->Adj[*V1].inicio->peso--;
                  encontrou=1;
                  *P=aux->peso;
                  ant->prox=aux->prox;
                  if (G->Adj[*V1].fim==aux)
                     G->Adj[*V1].fim=ant;
                  free(aux);
               }
               else {
                    ant=aux;
                    aux=aux->prox;
               }
         }

         if (G->direcionado==0) {
            if (encontrou) {
                encontrou=0;
                ant=G->Adj[*V2].inicio;
                aux=ant->prox;
                while ((aux!=NULL) && (!encontrou)) {
                    if (aux->v==*V1) {
                        G->Adj[*V2].inicio->peso--;
                        encontrou=1;
                        ant->prox=aux->prox;
                        if (G->Adj[*V2].fim==aux)
                            G->Adj[*V2].fim=ant;
                        free(aux);
                    }
                    else {
                        ant=aux;
                        aux=aux->prox;
                    }
                }
            }
         }
    }
}

/*função que libera memória do grafo
*/
void liberar_memoria(Grafo *G) {
     no_aresta *aux;
     int i;
     for (i=0; i<G->NumVertices; i++)
         while (G->Adj[i].inicio!=NULL) {
               aux=G->Adj[i].inicio;
               G->Adj[i].inicio=G->Adj[i].inicio->prox;
               free(aux);
         }
     free(G);
}

//função que retorna o grau de um vértice
int grau(Grafo *G, int *V) {
    return(G->Adj[*V].inicio->peso);
}

//função que retorna a cor de um vértice
int cor(Grafo *G, int *V) {
    return(G->Adj[*V].inicio->cor);
}

//função que atribui uma cor a um vértice do grafo
void atribui_cor(Grafo *G, int *V, int *cor) {
    G->Adj[*V].inicio->cor=*cor;
}

/*função que verifica se um vértice não tem vizinhos
*/
int ListaAdjVazia(Grafo *G, int *V, int *erro) {
    if (*V>=G->NumVertices) {
       *erro=1;
       return(1);
    }
    else {
         *erro=0;
         if (G->Adj[*V].inicio->prox==NULL)
            return(1);
         else return(0);
    }
}

/* indica o endereço do primeiro vértice na lista de adjacentes de V
*/
void PrimeiroListaAdj(Grafo *G, int *V, no_aresta **Adj, elem *P, int *erro) {
    if (*V>=G->NumVertices)
       *erro=1;
    else *erro=0;
    *Adj=G->Adj[*V].inicio->prox;
    *P=(*Adj)->peso;
}

/*retorna o vértice adjacente Adj da lista de adjacentes de V,
bem como o peso associado à aresta V-Adj
*/
void ProxAdj(Grafo *G, no_aresta **Adj, elem *P, int *erro) {
     *erro=0;
     *Adj=(*Adj)->prox;
     if (*Adj!=NULL)
        *P=(*Adj)->peso;
     else *P=-1;
}

//função auxiliar para busca em largura, utiliza o TAD fila
void visita_bfs(Grafo *G, int V, int distancia[], TipoCor cor[], int antecessor[]) {
     int peso, erro;
     no_aresta *Adj;

     Fila F;
     Cria(&F);

     cor[V]=cinza;
     distancia[V]=0;
     Entra(&F,&V,&erro);
     printf("No %d, distancia=%d, antecessor=%d\n",V,distancia[V],antecessor[V]);

     while (!EstaVazia(&F)) {
           Sai(&F,&V,&erro);
           if (!ListaAdjVazia(G,&V,&erro)) {
              PrimeiroListaAdj(G,&V,&Adj,&peso,&erro);
              while (Adj!=NULL) {
                    if (cor[Adj->v]==branco) {
                       cor[Adj->v]=cinza;
                       distancia[Adj->v]=distancia[V]+1;
                       antecessor[Adj->v]=V;
                       Entra(&F,&Adj->v,&erro);
                       printf("No %d, distancia=%d, antecessor=%d\n",Adj->v,distancia[Adj->v],antecessor[Adj->v]);
                    }
                    ProxAdj(G,&Adj,&peso,&erro);
              }
           }
           cor[V]=preto;
     }
}

//função para busca em largura, utiliza a função auxiliar anterior
void busca_largura(Grafo *G) {
     int V, distancia[MaxNumVertices], antecessor[MaxNumVertices], componentes_conexas;
     TipoCor cor[MaxNumVertices];

     componentes_conexas=0;

     printf("*** Sequencia de nos visitados na busca em largura ***\n\n");

     for (V=0; V<G->NumVertices; V++) {
         cor[V]=branco;
         distancia[V]=-1;
         antecessor[V]=-1;
     }
     for (V=0; V<G->NumVertices; V++)
         if (cor[V]==branco) {
            componentes_conexas++;
            visita_bfs(G,V,distancia,cor,antecessor);
         }

     //número de componentes conexas no grafo
     printf("Numero de componentes conexas no grafo: %d\n", componentes_conexas);
}

/* função auxiliar para busca em profundidade
*/
void visita_dfs(Grafo *G, int V, int *tempo, int d[], int t[], TipoCor cor[], int antecessor[])
{
    int erro, peso;
    no_aresta *Adj;

    cor[V]=cinza;
    (*tempo)++;
    d[V]=*tempo;

    if (!ListaAdjVazia(G,&V,&erro)) {
       PrimeiroListaAdj(G,&V,&Adj,&peso,&erro);
       while (Adj!=NULL) {
             if (cor[Adj->v]==branco) {
                antecessor[Adj->v]=V;
                visita_dfs(G,Adj->v,tempo,d,t,cor,antecessor);
             }
             ProxAdj(G,&Adj,&peso,&erro);
       }
    }

    cor[V]=preto;
    (*tempo)++;
    t[V]=*tempo;

    printf("No %d, descoberta=%d, termino=%d, antecessor=%d\n",V,d[V],t[V],antecessor[V]);
}

/* função para busca em profundidade, utiliza função auxiliar anterior
*/
void busca_profundidade(Grafo *G) {
     int V, tempo, d[MaxNumVertices], t[MaxNumVertices], antecessor[MaxNumVertices];
     TipoCor cor[MaxNumVertices];

     printf("*** Nos visitados na busca em profundidade ***\n\n");

     tempo=0;
     for (V=0; V<G->NumVertices; V++) {
         cor[V]=branco;
         antecessor[V]=-1;
     }
     for (V=0; V<G->NumVertices; V++)
         if (cor[V]==branco)
            visita_dfs(G,V,&tempo,d,t,cor,antecessor);
}

void imprimir(Grafo *G){
    int i;
    for(i = 0; i < G->NumVertices; i++){
        no_aresta *aux;
        aux = G->Adj[i].inicio;
        printf("%d peso: %d -> ", i, aux->peso);
        aux = aux->prox;
        while(aux != NULL){
            printf("%d ", aux->v);
            aux = aux->prox;
        }
        printf("\n");
    }
}
