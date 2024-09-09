#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 100

typedef struct{
    int level;
    char nome[20];
    double movimento;
}Personagem;

int main(){

    FILE *arquivo;
    Personagem personagem;
    char nArquivo[20];
    char nome[20];

    printf("Qual nome da campanha?\n");
    scanf("%s", nArquivo);

    for(int cont = 0; cont < LIMITE; cont++){
        if(nArquivo[cont] == '\0'){
            nArquivo[cont] = '.';
            nArquivo[cont + 1] = 't';
            nArquivo[cont + 2] = 'x';
            nArquivo[cont + 3] = 't';
            nArquivo[cont + 4] = '\0';
            break;
        }
    }
    if((arquivo = fopen(nArquivo, "rb")) == NULL){
        printf("deu pau :(");
        return 1;
    }

    printf("Qual nome do personagem a ser buscado?\n");
    scanf("%s", nome);
    
    fread(&personagem, sizeof(Personagem), 1, arquivo);
    

    while(!feof(arquivo)){
        if(strcmp(nome, personagem.nome) == 0){
            printf("nome: %s\nlevel: %d\nmovimento: %.1lf\n\n", personagem.nome, personagem.level, personagem.movimento);
            break;
        }
        else{
            fread(&personagem, sizeof(Personagem), 1, arquivo);
        }
    }

    fclose(arquivo);

    return 0;
}