#include <stdio.h>
#include <stdlib.h>
#include "contas.h"

int main(){

    FILE *arquivo;

    if((arquivo = fopen("clientela.dat", "r+b")) == NULL){
        printf("deu pau na abertura do arquivo :(");
        return 0;
    }  
    
    Cliente *memoria[5];
    Cliente *reservatorio[5];

    alocar(memoria, 5);
    alocar(reservatorio, 5);

    while(!feof(arquivo)){
        selecaoNatural(memoria, reservatorio, arquivo);
    }

    fclose(arquivo);

    for(int cont = 0; cont < 5; cont++){
        free(memoria[cont]);
        free(reservatorio[cont]);
    }
    return 0;
}