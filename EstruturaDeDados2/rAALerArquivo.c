#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo;
    char classe[15];
    int caractere;

    printf("qual classe abrir?\n");
    scanf("%s", classe);

    for(int cont = 0; cont < 15; cont++){
        if(classe[cont] == '\0'){
            classe[cont] = '.';
            classe[cont + 1] = 't';
            classe[cont + 2] = 'x';
            classe[cont + 3] = 't';
            classe[cont + 4] = '\0';
            break;
        }
    }

    if((arquivo = fopen(classe, "r")) == NULL){
        printf("ih deu pau bixo");
        return 1;
    }

    caractere = fgetc(arquivo);

    while(!feof(arquivo)){
        putchar(caractere);
        caractere = fgetc(arquivo);
    }

    fclose(arquivo);

    return 0;
}