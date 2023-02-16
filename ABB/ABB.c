#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

ABB* criar(void) {
    ABB *Aux = (ABB*) malloc(sizeof(ABB));
    if(Aux != NULL)
        Aux->raiz = NULL;
    return(Aux);
}

int buscar(no *p, elem *x){
    if(p == NULL)
        return(0);
    else if(p->info == *x)
        return(1);
    else if(*x < p->info)
        return(buscar(p->esq, x));
    else
        return(buscar(p->dir, x));
}

int inserir(no* *p, elem *x){
    if(*p == NULL){
        *p = (no*) malloc(sizeof(no));
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        (*p)->info = *x;
        return(1);
    }
    else if((*p)->info == *x)
        return(0);
    else if(*x < (*p)->info)
        return(inserir(&(*p)->esq, x));
    else
        return(inserir(&(*p)->dir, x));
}

int remover(no **p, elem *x){
    no *aux;
    if(*p == NULL)
        return(0);
    else if(*x < (*p)->info)
        return(remover(&(*p)->esq, x));
    else if(*x > (*p)->info)
        return(remover(&(*p)->dir, x));
    else {
        // else if(*x == (*p)->info)
        // caso 1: no sem filhos
        if(((*p)->esq == NULL) && ((*p)->dir == NULL)){
            free(*p);
            *p = NULL;
            return(1);
        }
        // caso2a: so tem filho direito
        else if((*p)->esq == NULL){
            aux = *p;
            *p = (*p)->dir;
            free(aux);
            return(1);
        }
        // caso2b: so tem filho esquerdo
        else if((*p)->dir == NULL){
            aux = *p;
            *p = (*p)->esq;
            free(aux);
            return(1);
        }
        // caso3: ha dois filhos
        else {
            (*p)->info = busca_maior(&(*p)->esq);
            return(remover(&(*p)->esq, &(*p)->info));
        }

    }
}

elem busca_maior(no **p){
    no *aux;
    aux = *p;
    while(aux != NULL)
        aux = aux->dir;
    return(aux->info);
}

void pre_ordem(no *p){
    if(p != NULL){
        printf("%d\n", p->info);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void Finalizar(no *p){
    if(p != NULL){
        Finalizar(p->esq);
        Finalizar(p->dir);
        free(p);
    }
}

// Para verificar se ABB é cheia
int profundidade(no *p){
    int d = 0;
    while(p != NULL){
        d++;
        p = p->esq;
    }
    return(d);
}

int eh_cheia(no *p, int d, int nivel){
    if(p == NULL)
        return(1);
    else if((p->esq == NULL) && (p->dir == NULL))
        return(d == nivel + 1);
    else if((p->esq == NULL) || (p->dir == NULL))
        return(0);
    else
        return(eh_cheia(p->esq, d, nivel+1) && eh_cheia(p->dir, d, nivel+1));
}

int Eh_Cheia(no *p){
    int d;
    d = profundidade(p);
    return(eh_cheia(p, d, 0));
}


int conta_no(no *p){
    if(p == NULL)
        return(0);
    else
        return(1 + conta_no(p->esq) + conta_no(p->dir));
}

int soma_valor_dos_nos(no *p){
    if(p == NULL)
        return(0);
    else
        return(p->info + soma_valor_dos_nos(p->esq) + soma_valor_dos_nos(p->dir));
}
