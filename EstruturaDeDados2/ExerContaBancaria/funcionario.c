#include <stdio.h>
#include "funcionario.h"
#include <string.h>
#include <stdlib.h>

Funcionario *criarFuncionario(){
    Funcionario *funcionario = (Funcionario *) malloc(sizeof(Funcionario));
    if(funcionario) memset(funcionario, 0, sizeof(Funcionario));

    printf("DIGITE O CODIGO DO FUNCIONARIO\n");
    scanf("%d", &funcionario->codigo);

    printf("DIGITE O NOME DO FUNCIONARIO\n");
    scanf("%s", funcionario->nome);
    
    printf("DIGITE O CPF DO FUNCIONARIO\n");
    scanf("%s", funcionario->cpf);

    printf("DIGITE A DATA DE NASCIMENTO DO FUNCIONARIO\n");
    scanf("%s", funcionario->dataNascimento);

    printf("DIGITE O SALARIO DO FUNCIONARIO");
    scanf("%lf")

    funcionario->salario = salario;

    return funcionario;
}

void salvar(Funcionario *funcionario, FILE *conta){

    fwrite(&funcionario->codigo, sizeof(int), 1, conta);
    fwrite(funcionario->nome, sizeof(char), sizeof(funcionario->nome), conta);
    fwrite(funcionario->cpf, sizeof(char), sizeof(funcionario->cpf), conta);
    fwrite(funcionario->dataNascimento, sizeof(char), sizeof(funcionario->dataNascimento), conta);
    fwrite(&funcionario->salario, sizeof(double), 1, conta);
    rewind(conta);
}

void lerTodosFuncionarios(FILE *conta){
    Funcionario *funcionario = (Funcionario *) malloc(sizeof(Funcionario));

    while(fread(&funcionario->codigo, sizeof(int), 1, conta) == 1){
        fread(funcionario->nome, sizeof(char), sizeof(funcionario->nome), conta);
        fread(funcionario->cpf, sizeof(char), sizeof(funcionario->cpf), conta);
        fread(funcionario->dataNascimento, sizeof(char), sizeof(funcionario->dataNascimento), conta);
        fread(&funcionario->salario, sizeof(double), 1, conta);

        printf("________________________\nCodigo: %d\nNome: %s\nCPF: %s\nData de Nascimento: %s\nSalario: %.2lf\n", funcionario->codigo, funcionario->nome, funcionario->cpf, funcionario->dataNascimento, funcionario->salario);
    }
    printf("________________________\n");
    free(funcionario);
    rewind(conta);
}
void lerFuncionario(FILE *conta, int codigo){

    Funcionario *funcionario = (Funcionario *) malloc(sizeof(Funcionario));
    if(funcionario) memset(funcionario, 0, sizeof(Funcionario));

    do{
        fread(&funcionario->codigo, sizeof(int), 1, conta);
        fread(funcionario->nome, sizeof(char), sizeof(funcionario->nome), conta);
        fread(funcionario->cpf, sizeof(char), sizeof(funcionario->cpf), conta);
        fread(funcionario->dataNascimento, sizeof(char), sizeof(funcionario->dataNascimento), conta);
        fread(&funcionario->salario, sizeof(double), 1, conta);
    }while(funcionario->codigo != codigo);

    printf("________________________\nCodigo: %d\nNome: %s\nCPF: %s\nData de Nascimento: %s\nSalario: %.2lf\n________________________\n", funcionario->codigo, funcionario->nome, funcionario->cpf, funcionario->dataNascimento, funcionario->salario);
    
}