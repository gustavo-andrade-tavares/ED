#define MaxNumVertices 100
#define infinito 9999

typedef int elem;
typedef struct grafo Grafo;

typedef enum {
        branco, cinza, preto
} TipoCor;

Grafo* criar(int*, int*, int*);
void inserir_aresta(Grafo*, int*, int*, elem*, int*);
int existe_aresta(Grafo*, int*, int*, int*);
void retirar_aresta(Grafo*, int*, int*, elem*, int*);
void liberar_memoria(Grafo*);
int grau(Grafo*, int*);
int cor(Grafo*, int*);
void atribui_cor(Grafo*, int*, int*);
void busca_largura(Grafo*);
void busca_profundidade(Grafo*);
void imprimir(Grafo*);
