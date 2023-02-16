#include<stdio.h>
#include<stdlib.h>
#include "fila_encadeada.h"


typedef struct no_{
  elem elem;
  struct no_* prox;
}No;

struct fila_{
  No* ini;
  No* fim;
  int nelem;
};

//cria a fila
Fila* cria_fila(){
  Fila* f = malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  f->nelem = 0;
  return f;
}

//adiciona um item na fila
int fila_add(Fila* f, elem e){
  No* n = malloc(sizeof(No));

  if(n==NULL) return 1;

  n->elem = e;
  n->prox = NULL; //como ele é o ultimo seu prox é NULL

  if(f->nelem == 0){ //se for o primeiro item
    f->ini = n;
    f->fim = n;
  }else{
    f->fim->prox = n;
    f->fim = n;
  }

  f->nelem++;

  return 0;
}

//retira um item da lista
int fila_pop(Fila* f, elem* e){
  No* no_aux;
  if(f == NULL) return 1;//se a fila não existe
  if(f->nelem == 0) return 2;//se a fila está vazia

  *e = f->ini->elem;

  no_aux = f->ini;

  f->ini = no_aux->prox;

  no_aux->prox = NULL;
  free(no_aux);

  f->nelem --;
  return 0;
}

//função que faltou na monitoria
//destroi a lista
int fila_destruir(Fila** f){
  if(f == NULL) return 1; //se a fila não existe

  No* n = (*f)->ini;
  No* aux;

  while(n != NULL){//percorre a fila apagando os nós
    aux = n->prox;
    free(n);
    n = aux;
  }

  free(*f);//apaga a fila
  (*f) = NULL;
  return 0;
}

/*
OBS: A função fila_destruir recebe como parametro Fila** para que seja
possvel mudar o valor de f para NULL ((*f) = NULL), isso previne erros
caso o programa tente usar outras funçoes em uma fila já destruida.
Para usar a função passamos &f com argumento.
*/
