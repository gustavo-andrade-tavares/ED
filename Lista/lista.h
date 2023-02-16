
typedef char elem;

typedef struct bloco{
    elem info;
    struct bloco *prox;
} no;

typedef struct {
    no *inicio, *fim;
    //int total;
} Lista;

Lista* Criar(void);

void Inserir(Lista*, elem*, int*);

void Finalizar(Lista*);

int Esta_na_Lista(Lista*, elem*);

int Tamanho(Lista*);

int Tamanho_rec(no*);

void Eliminar(Lista*, elem*, int*);
