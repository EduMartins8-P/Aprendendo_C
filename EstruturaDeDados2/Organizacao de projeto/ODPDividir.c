#include <stdio.h>

void dividir(double numerador, double denominador){
    if(denominador == 0){
        printf("indefinicao matematica");
    }
    else{
        printf("%.1lf", numerador/denominador);
    }

}