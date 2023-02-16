// Lista duplamente encadeada

typedef char elem;

typedef struct bloco {
    elem item;
    struct bloco *anterior, *proximo;
} no;

typedef struct {
    no *inicio, *fim;
} Lista_D;

Lista_D* Cria_Lista(void);
int Inserir(Lista_D*, elem*);
int Imprimir(Lista_D*);
int Imprimir_inv(Lista_D*);
int Apagar_Lista(Lista_D*);
