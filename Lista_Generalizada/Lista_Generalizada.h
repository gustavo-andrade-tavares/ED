// Lista generalizada

typedef char elem;

typedef struct bloco {
    union{
        elem atomo;
        struct bloco *sublista;
    } info;
    int tipo_escolhido;
    struct bloco *prox;
} no;

typedef struct {
    no *inicio, *fim;
} Lista_Gen;

Lista_Gen* Cria(void);
no* Insere_atomo(void);
int Inserir_el(Lista_Gen*, int*);
int Inserir_na_subl(no*);
no* Insere_sublista(void);
void Concatena(Lista_Gen*, no*);
int Inserir_elemento(Lista_Gen*, int*);
void Imprimir(Lista_Gen*);
void Imprimir_sublista(no*);
void Apagar(Lista_Gen*);
