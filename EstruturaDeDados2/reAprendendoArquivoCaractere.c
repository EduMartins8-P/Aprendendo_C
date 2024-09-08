#include <stdio.h>

int main(){
    FILE *arquivo;
    char nome[20];
    int caractere;

    printf("nome do arquivo\n");
    scanf("%s", nome);
    for(int cont = 0; cont < 15; cont++){
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
        printf("ih deu pau bixo");
        return 1;
    }

    printf("insira caracteres\n");
    while(caractere != EOF){
        fputc(caractere, arquivo);
        caractere = getchar();
    }

    fclose(arquivo);

    return 0;
}