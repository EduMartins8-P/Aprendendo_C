#include <stdio.h>
#include <stdlib.h>
#include "contas.h"

void alocar(Cliente *memoria[], int quantos){
    for(int cont = 0; cont < quantos; cont++){
        memoria[cont] = (Cliente *) malloc(sizeof(Cliente));
    }
}

void gravarMenorNoRegistro(FILE *arquivo, Cliente *cliente){   
    fwrite(cliente, sizeof(Cliente), 1, arquivo);
}

void teste(Cliente *cliente){
    printf("\n[[[%d %s %s]]]\n", cliente->codCliente, cliente->nome, cliente->dataNascimento);
}

Cliente* receberCliente(FILE *arquivo, long posicao){
    Cliente *aux = (Cliente *) malloc(sizeof(Cliente));

    fread(aux, sizeof(Cliente), 1, arquivo);
    return aux;
}