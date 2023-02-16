
typedef int elem;

typedef struct bloco {
    elem info;
    struct bloco *esq, *dir;
} no;

typedef struct {
    no *raiz;
} ABB;

ABB* criar(void);
int buscar(no*, elem*);
int inserir(no**, elem*);
int remover(no**, elem*);
elem busca_maior(no**);
void pre_ordem(no*);
void Finalizar(no*);

int profundidade(no*);
int eh_cheia(no*, int, int);
int Eh_Cheia(no*);
int conta_no(no*);
int soma_valor_dos_nos(no*);
