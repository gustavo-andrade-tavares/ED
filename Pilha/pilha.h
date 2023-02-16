// Pilha estatica e sequencial
#define TamPilha 30

typedef float elem;

typedef struct {
    int topo, total;
    elem itens[TamPilha];
} Pilha;

void Create(Pilha*);

void Empty(Pilha*);

int IsEmpty(Pilha*);

int IsFull(Pilha*);

void Push(Pilha*, elem*, int*);

void Pop(Pilha*, elem*, int*);

elem Top(Pilha*, int*);

void Imprimir(Pilha*);

int Iguais(Pilha, Pilha);

void Inverter(Pilha*);

int Tamanho(Pilha*);

void Teste_de_Tamanho(Pilha*, Pilha*);
