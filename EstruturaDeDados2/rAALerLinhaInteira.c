#include <stdio.h>
#include <stdlib.h>
#define LIMITE 100

int main(){
    FILE *arquivo;
    char nome[LIMITE];
    char leitura[LIMITE];

    printf("qual nome do arquivo a ser lido?\n");
    scanf("%s", nome);

    for(int cont = 0; cont < LIMITE; cont++){
        if(nome[cont] == '\0'){
            nome[cont] = '.';
            nome[cont + 1] = 't';
            nome[cont + 2] = 'x';
            nome[cont + 3] = 't';
            nome[cont + 4] = '\0';
            break;
        }
    }
    if((arquivo = fopen(nome, "r")) == NULL){
        printf("deu pau :(");
        return 1;
    }

    fgets(leitura, LIMITE, arquivo);

    while(!feof(arquivo)){
        puts(leitura);
        fgets(leitura, LIMITE, arquivo);
    }

    fclose(arquivo);

    return 0;
}