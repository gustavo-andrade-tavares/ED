#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
// P1: Copas P2: Espadas P3: Paus P4: Ouros A= 65, J = 74, Q = 81
int main(void) {
    elem x[13], t, u, y[13]; // z[13], w[13];
    char resp;
    int erro, i, vi, qx, qy;
    Pilha P1, P2; // P3, P4;
    Create(&P1);
    Create(&P2);
    /*
    Create(&P3);
    Create(&P4); */

    printf("Preenchendo Copas:\n");
    for(i = 0; i < 13; i++) {
        printf("Digite uma carta de copas[%d]: ", i);
        scanf("%f", &x[i]);
        Push(&P1, &x[i], &erro);
    }

    t = Top(&P1, &erro);
    printf("A carta que esta no topo do naipe copas eh: %.2f\n", t);

    printf("Deseja retira-la?[S/N]: ");
    scanf("%s", &resp);

    if(resp == 'S')
        Pop(&P1, &x[i], &erro);
    else
        printf("Ok\n");

    Imprimir(&P1);

    printf("Preenchendo espadas:\n");
    for(i = 0; i < 13; i++) {
        printf("Digite uma carta de espadas[%d]: ", i);
        scanf("%f", &y[i]);
        Push(&P2, &y[i], &erro);
    }
    u = Top(&P2, &erro);
    printf("A carta que esta no topo do naipe espadas eh: %.2f\n", u);
    printf("Deseja retira-la?[S/N]: ");
    scanf("%s", &resp);

    if(resp == 'S')
        Pop(&P2, &y[i], &erro);
    else
        printf("Ok\n");

    Imprimir(&P2);

    vi = Iguais(P1, P2);

    if(vi == 1)
        printf("As pilhas de cartas de copas e espadas estao iguais.\n");
    else
        printf("As pilhas estão diferentes.\n");

    qx = Tamanho(&P1);
    printf("O tamanho da pilha P1 eh: %d\n", qx);

    qy = Tamanho(&P2);
    printf("O tamanho da pilha P2 eh: %d\n", qy);

    Teste_de_Tamanho(&P1, &P2);

    return(0);
}
