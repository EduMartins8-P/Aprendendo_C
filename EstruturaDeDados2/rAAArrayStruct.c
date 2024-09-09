#include <stdio.h>
#include <stdlib.h>
#define LIMITE 100

typedef struct{
    int level;
    char nome[20];
    double movimento;
}Personagem;

int main(){

    FILE *arquivo;
    Personagem party[3];
    Personagem aux[3];
    char nArquivo[20];

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
    if((arquivo = fopen(nArquivo, "w+")) == NULL){
        printf("deu pau :(");
        return 1;
    }

    for(int cont = 0; cont < 3; cont++){
        printf("Qual nome do personagem %d\n", cont + 1);
        scanf("%s", party[cont].nome);
        printf("Qual level do personagem %s?\n", party[cont].nome);
        scanf("%d", &party[cont].level);
        printf("Quanto de movimento tem o personagem %s\n", party[cont].nome);
        scanf("%lf", &party[cont].movimento);
        if(fwrite(&party[cont], sizeof(Personagem), 1, arquivo) != 1){
            printf("o personagem %d deu pau na escrita do arquivo D:", cont + 1);
            return 1;
        }
    }
    rewind(arquivo);
    printf("\n\n\n\n\n\n");

    if(fread(&aux, 3*sizeof(Personagem), 1, arquivo) != 1){
        printf("Deu pau na leitura do arquivo D:");
        return 1;
    }
    
    for(int cont = 0; cont < 3; cont++){
        printf("nome: %s\nlevel: %d\nmovimento: %.1lf\n\n", aux[cont].nome, aux[cont].level, aux[cont].movimento);
    }
    
    fclose(arquivo);

    return 0;
}
