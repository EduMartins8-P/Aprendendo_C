#include <stdio.h>
#include <stdlib.h>
#define LIMITE 100

int main(){
    FILE *arquivo;
    char nome[LIMITE];
    char escrita[LIMITE];

    printf("qual nome do arquivo a ser escrito?\n");
    scanf("%s", nome);

    for(int cont = 0; cont > -1; cont++){
        if(nome[cont] == '\0'){
            nome[cont] = '.';
            nome[cont + 1] = 't';
            nome[cont + 2] = 'x';
            nome[cont + 3] = 't';
            nome[cont + 4] = '\0';
            break;
        }
    }
    if((arquivo = fopen(nome, "w+")) == NULL){
        printf("deu pau :(");
        return 1;
    }

    fgets(escrita, LIMITE, stdin);

    while(!feof(stdin)){
        fputs(escrita, arquivo);
        fgets(escrita, LIMITE, stdin);
    }

    fclose(arquivo);

    return 0;
}