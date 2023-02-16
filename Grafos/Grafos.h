// Matriz de adjacencias

#define MaxNumVertices 100
#define SemArestas 0
typedef int elem;

typedef struct {
    elem m[MaxNumVertices][MaxNumVertices];
    int NumVertices, direcionado;
} Grafo;

Grafo* Criar_grafo(int*,int*,int*);
void Finalizar(Grafo*);
void Esvaziar(Grafo*);
void Inserir_Aresta(Grafo*, int*, int*, elem*, int*);
elem Retirar_aresta(Grafo*, int*, int*, int*);
int Existe_Aresta(Grafo*, int*, int*, int*);
void Imprimir_matriz_adj(Grafo*);
