#include <stdio.h>
#include <stdlib.h>
int main(){
    int aleatorio[50][50], input = 0;
    for(int cont = 0; cont < 50; cont++){
        for(int cont2 = 0; cont2 < 50; cont2++){
            aleatorio[cont][cont2] = rand();
            input += aleatorio[cont][cont2];}}
    printf("Seu resultado: %d", input);
    return 0;}
