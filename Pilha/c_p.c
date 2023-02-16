#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"
/*
int main(void) {
    elem x, y, z;
    int erro, i;
    char exp[TamPilha], temp[10];
    Pilha P;
    Create(&P);

    printf("Digite uma expressão posfixa: ");
    fgets(exp, TamPilha, stdin);

    i = 0;
    while (i < strlen(exp)-1) {
        if((exp[i]=='+') || (exp[i]=='-') || (exp[i]=='*') || (exp[i]=='/')) {
            Pop(&P, &x, &erro);
            Pop(&P, &y, &erro);
            if(exp[i]=='+')
                z = x + y;
            else if(exp[i]=='-')
                z = y - x;
            else if(exp[i]=='*')
                z = x * y;
            else if(exp[i]=='/')
                z = x / y;

            Push(&P, &z, &erro);
            i++;
        }
        else if(exp[i]== ' ')
            i++;

        else {
            strcpy(temp, "");
            while((exp[i]=='0') && (exp[i]=='9')) {
                strncat(temp, &exp[i], 1);
                i++;
            }
            z = atof(temp);
            Push(&P, &z, &erro);
        }
    }
    z = Top(&P, &erro);
    printf("Usuario, o resultado da expressao eh: %f\n", z);
    system("pause");
    return(0);
} */
