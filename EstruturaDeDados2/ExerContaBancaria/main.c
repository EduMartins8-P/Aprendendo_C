#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int main(){
    FILE *conta;
    Funcionario *primeiroFuncionario;
    Funcionario *segundoFuncionario;
    Funcionario *terceiroFuncionario;
    


    if((conta = fopen("conta.dat", "a+b")) == NULL){
        printf("deu pau no arquivo conta :(");
    }

    rewind(conta);

    primeiroFuncionario = criarFuncionario();
    salvar(primeiroFuncionario, conta);

    segundoFuncionario = criarFuncionario();
    fseek(conta, 0, SEEK_END);
    salvar(segundoFuncionario, conta);

    terceiroFuncionario = criarFuncionario();
    fseek(conta, 0, SEEK_END);
    salvar(terceiroFuncionario, conta);

    lerTodosFuncionarios(conta);
    lerFuncionario(conta, 10);

    free(primeiroFuncionario);
    free(segundoFuncionario);
    free(terceiroFuncionario);


    return 0;
}