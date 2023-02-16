// Listas de adjacencias

#define MaxNumVertices 100
typedef int elem;

typedef struct no_aresta{
    int V;
    elem Peso;
    struct no_aresta *prox;
} no_aresta;

typedef struct {
    no_aresta *inicio, *fim;
    int grau;
} no_vertice;

typedef struct {
    no_vertice Adj[MaxNumVertices];
    int NumVertices, direcionado;
} Grafo;

Grafo* Criar_grafo(int*, int*, int*);
int Inserir_Aresta(Grafo*, int*, int*, int*);
int Existe_Aresta(Grafo*, int*, int*);
int Retirar_Aresta(Grafo*, int*, int*);
void Finalizar(Grafo*);

