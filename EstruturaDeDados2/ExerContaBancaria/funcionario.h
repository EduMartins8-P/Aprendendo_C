typedef struct Funcionario{
    int codigo;
    char nome[50];
    char cpf[15];
    char dataNascimento[11];
    double salario;
}Funcionario;

Funcionario *criarFuncionario();
void salvar(Funcionario *funcionario, FILE *conta);
void lerTodosFuncionarios(FILE *conta);
void lerFuncionario(FILE *conta, int codigo);