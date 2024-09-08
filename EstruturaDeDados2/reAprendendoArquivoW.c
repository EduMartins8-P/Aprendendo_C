#include <stdio.h>

int main(){

    FILE *arquivo;

    char *nome = "eitabixo.txt";

    arquivo = fopen(nome, "w");

    if(arquivo == NULL){
        printf("deu pau :(");
        return 1;
    }

    printf("eita como arquiva");

    return 0;
}