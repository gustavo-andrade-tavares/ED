#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Generalizada.h"

Lista_Gen* Cria(void){
    Lista_Gen* Laux = (Lista_Gen*) malloc(sizeof(Lista_Gen));
    if(Laux == NULL)
        return(NULL);
    Laux->inicio = NULL;
    return(Laux);
}

no* Insere_atomo(void){
    no *at = (no*) malloc(sizeof(no));
    if(at == NULL)
        return(NULL);

    elem item;
    printf("Digite uma letra: ");
    scanf("%s", &item);

    at->tipo_escolhido = 0;
    at->info.atomo = item;
    at->prox = NULL;

    return(at);
}

int Inserir_el(Lista_Gen *L, int *tp){
    if(*tp == 0){
        no *at = (no*) malloc(sizeof(no));
        if(at == NULL)
            return(1);

        elem item;
        printf("Digite uma letra: ");
        scanf("%s", &item);

        at->tipo_escolhido = 0;
        at->info.atomo = item;
        at->prox = NULL;

        if(L->inicio == NULL){
            L->inicio = at;
            L->fim = at;
        }
        else{
            L->fim->prox = at;
            L->fim = at;
        }
    }
    else{
        no *sbl = (no*) malloc(sizeof(no));
        if(sbl == NULL)
            return(1);

        sbl->tipo_escolhido = 1;
        sbl->info.sublista = NULL;
        sbl->prox = NULL;

        if(L->inicio == NULL){
            L->inicio = sbl;
            L->fim = sbl;
        }
        else{
            L->fim->prox = sbl;
            L->fim = sbl;
        }

        int q;
        printf("Digite a quantidade de elementos da sublista: ");
        scanf("%d", &q);

        for(int i = 0; i < q; i++){
            Inserir_na_subl(sbl);
        }
    }
    return(0);
}

int Inserir_na_subl(no *p_sbl){
    int tipo;
    printf("Digite o tipo: ");
    scanf("%d", &tipo);
    if(tipo == 0){
        no *pa;
        pa = Insere_atomo();

        if(p_sbl->info.sublista == NULL)
            p_sbl->info.sublista = pa;
        else{
            no *auxsub;
            auxsub = p_sbl->info.sublista;
            while(auxsub != NULL){
                if(auxsub->prox == NULL){
                    auxsub->prox = pa;
                    break;
                }
                auxsub = auxsub->prox;
            }
        }
    }
    else{
        printf("Testando.\n");
    }
    return(0);
}

no* Insere_sublista(void){
    char resp;
    int q, tp, i;

    no *sbl = (no*) malloc(sizeof(no));
    if(sbl == NULL)
        return(NULL);

    sbl->tipo_escolhido = 1;
    sbl->info.sublista = NULL;
    sbl->prox = NULL;

    printf("Deseja inserir na sublista? s ou n: ");
    scanf("%s", &resp);

    if(resp == 's'){
        printf("Quantos elementos deseja inserir?: ");
        scanf("%d", &q);

        for(i = 0; i < q; i++){
            printf("Digite o tipo do elemento(0 ou 1): ");
            scanf("%d", &tp);

            if(tp == 0){
                if(sbl->info.sublista == NULL)
                    sbl->info.sublista = Insere_atomo();
                else{
                    no *auxsub;
                    auxsub = sbl->info.sublista;
                    while(auxsub != NULL){
                        if(auxsub->prox == NULL){
                            auxsub->prox = Insere_atomo();
                            break;
                        }
                        auxsub = auxsub->prox;
                    }
                }
            }
            else{
                if(sbl->info.sublista == NULL)
                    sbl->info.sublista = Insere_sublista();
                else{
                    no *auxsub;
                    auxsub = sbl->info.sublista;
                    while(auxsub != NULL){
                        if(auxsub->prox == NULL){
                            auxsub->prox = Insere_sublista();
                            break;
                        }
                        auxsub = auxsub->prox;
                    }
                }
            }
        }
    }

    else{
        printf("Nenhum elemento inserido na sublista.\n");
    }

    return(sbl);
}

void Concatena(Lista_Gen *L, no *l){
    if(L->inicio == NULL){
        L->inicio = l;
        L->fim = l;
    }
    else{
        L->fim->prox = l;
        L->fim = l;
    }
}

int Inserir_elemento(Lista_Gen *L, int *tp){
    if(*tp == 0){
        no *at;
        at = Insere_atomo();
        Concatena(L, at);
    }

    else{
        no *sl;
        sl = Insere_sublista();
        Concatena(L, sl);
    }
    return(0);
}

void Imprimir(Lista_Gen *L){
    no *aux;
    aux = L->inicio;
    printf("( ");
    while(aux != NULL){
        if(aux->tipo_escolhido == 0){
            printf("%c", aux->info.atomo);
        }
        else{
            Imprimir_sublista(aux);
        }
        aux = aux->prox;
    }
    printf(" )");
}

void Imprimir_sublista(no *p_sbl){
    no *aux_sub;
    aux_sub = p_sbl->info.sublista;
    printf("( ");
    while(aux_sub != NULL){
        printf("%c ", aux_sub->info.atomo);
        aux_sub = aux_sub->prox;
    }
    printf(" )");
}

void Apagar(Lista_Gen *L){
    no *aux;
    aux = L->inicio;
    while(aux != NULL){
        L->inicio = L->inicio->prox;
        free(aux);
        aux = L->inicio;
    }
}
