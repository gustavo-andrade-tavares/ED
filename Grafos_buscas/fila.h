#define TamFila 100

typedef int elem;

typedef struct {
    int inicio, fim, total;
    elem itens[TamFila];
} Fila;

void Cria(Fila*);

void Esvazia(Fila*);

int EstaVazia(Fila*);

int EstaCheia(Fila*);

void Entra(Fila*, elem*, int*);

void Sai(Fila*, elem*, int*);

