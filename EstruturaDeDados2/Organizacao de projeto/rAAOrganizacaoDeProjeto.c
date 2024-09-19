#include <stdio.h>
#include <string.h>
#include "operacoes.h"

int main(){

    char controle[20] = "";
    double n1, n2;

    while(strcmp(controle, "encerrar") != 0){
        printf("\n\n\n\nqual operacao?\n");
        scanf("%s", controle);

        if(strcmp(controle, "soma") == 0){
            printf("insira parcela 1 e parcela 2\n");
            scanf("%lf %lf", &n1, &n2);
            soma(n1, n2);
        }
        if(strcmp(controle, "subtracao") == 0){
            printf("insira parcela 1 e parcela 2\n");
            scanf("%lf %lf", &n1, &n2);
            subtrair(n1, n2);
        }
        if(strcmp(controle, "multiplicacao") == 0){
            printf("insira fator 1 e fator 2\n");
            scanf("%lf %lf", &n1, &n2);
            multiplicar(n1, n2);
        }
        if(strcmp(controle, "divisao") == 0){
            printf("insira numerador e o denominador\n");
            scanf("%lf %lf", &n1, &n2);
            multiplicar(n1, n2);
        }
    }


    return 0;
}