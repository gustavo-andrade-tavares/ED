#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    Lista *L;
    L = Criar();
    if(L == NULL)
        printf("Erro, sem memoria");
}
