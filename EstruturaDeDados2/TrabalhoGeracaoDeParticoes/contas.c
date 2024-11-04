#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contas.h"

int contadorArquivo = 1;

char* nomeArquivo(){
    char valor[10];
    sprintf(valor, "%d", contadorArquivo);
    int tamanho = strlen(valor);

    char *nome = (char *) malloc(12 + tamanho);

    for(int cont = 0; cont < 12+tamanho; cont++){
        nome[cont] = '0';
    }
    
    nome[0] = 'a';
    nome[1] = 'r';
    nome[2] = 'q';
    nome[3] = 'u';
    nome[4] = 'i';
    nome[5] = 'v';
    nome[6] = 'o';
    nome[7 + tamanho] = '.';
    nome[8 + tamanho] = 'd';
    nome[9 + tamanho] = 'a';
    nome[10 + tamanho] = 't';
    nome[11 + tamanho] = '\0';

    for(int cont = 0; cont < tamanho; cont++){
        nome[7 + cont] = valor[cont];
    }

    contadorArquivo++;
    return nome;
}

Cliente* menorCodigo(Cliente *memoria[]){

    Cliente *aux = memoria[0];

    for(int cont = 0; cont < 5; cont++){
        if(aux->codCliente > memoria[cont]->codCliente){
            aux = memoria[cont];
        }
    }
    return aux;
}

void selecaoNatural(Cliente *memoria[], Cliente *reservatorio[], FILE *arquivo){

    FILE *arquivoAux;
    Cliente *aux;
    int controleMemoria = 0;
    int controleReservatorio = 0;

    for(int cont = 0; cont < 5; cont++){
        memoria[cont] = receberCliente(arquivo, ftell(arquivo));
    }

    if((arquivoAux = fopen(nomeArquivo(), "w+b")) == NULL){
        printf("deu pau na abertura do arquivo %d :(", contadorArquivo);
    }

    while(controleReservatorio < 5){

        aux = menorCodigo(memoria);

        gravarMenorNoRegistro(arquivoAux, aux);

        for(int cont = 0; cont < 5; cont++){      //substitui o que foi pra particao por outro  do arquivo  
            if(aux->codCliente == memoria[cont]->codCliente){
                memoria[cont] = receberCliente(arquivo, ftell(arquivo));
                break;                                                    
                controleMemoria = cont;
            }
        }

        while(memoria[controleMemoria]->codCliente < aux->codCliente){
            reservatorio[controleReservatorio] = memoria[controleMemoria];
            controleReservatorio++;                                           
            if(controleReservatorio == 4){
                fclose(arquivoAux);
                break;
            }
        }
    }

    fclose(arquivoAux);
    memoria = reservatorio;
}