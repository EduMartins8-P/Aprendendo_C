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
    char nArquivo[20];
    Personagem personagem;
    Personagem aux;

    printf("Qual nome?\n");
    scanf("%s", nArquivo);
    strcpy(personagem.nome, nArquivo);

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
    if((arquivo = fopen(nArquivo, "w+")) == NULL){
        printf("deu pau :(");
        return 1;
    }

    printf("Qual level do personagem %s?\n", personagem.nome);
    scanf("%d", &personagem.level);
    printf("Quanto de movimento tem o personagem %s\n", personagem.nome);
    scanf("%lf", &personagem.movimento);

    if(fwrite(&personagem, sizeof(Personagem), 1, arquivo ) != 1){
        printf("deu pau na escrita :(");
    }

    rewind(arquivo);

    if(fread(&aux, sizeof(Personagem), 1, arquivo) != 1){
        printf("deu pau na leitura :(");
    }

    printf("nome: %s\nlevel: %d\nmovimento: %lf", aux.nome, aux.level, aux.movimento);

    fclose(arquivo);

    return 0;
}