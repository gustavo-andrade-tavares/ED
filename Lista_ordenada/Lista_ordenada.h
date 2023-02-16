// Lista encadeada ordenada

typedef struct bloco{
    char nome[30];
    struct bloco *prox;
} no;

typedef struct {
    no *inicio;
} Lista_Ord;

Lista_Ord* Cria(void);
int IsEmpty(Lista_Ord*);
no* Busca(Lista_Ord*, char*);
int Inserir(Lista_Ord*, char*);
int Remover(Lista_Ord*, char*);
void Imprimir(Lista_Ord*);
void Apagar(Lista_Ord*);
