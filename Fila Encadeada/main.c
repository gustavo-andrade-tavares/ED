#include<stdio.h>
#include<stdlib.h>
#include "fila_encadeada.h"


int main(void){
  Fila* f = cria_fila();
  int elem;
  for(int i=0; i<=20; i+=2){
    if(fila_add(f, i)) return 1;
  }


  while(fila_pop(f, &elem) == 0){
    printf("%d\n", elem);
  }

  fila_destruir(&f);

  return 0;
}

