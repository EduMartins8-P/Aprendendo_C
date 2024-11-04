typedef struct{
    int codCliente;
    char nome[50];
    char dataNascimento[20];
}Cliente;


//Em contas
char *nomeArquivo();
Cliente* menorCodigo(Cliente *memoria[]);
void selecaoNatural(Cliente *memoria[], Cliente *reservatorio[], FILE *arquivo);

//Em utilidades
void gravarMenorNoRegistro(FILE *arquivo, Cliente *Cliente);
void alocar(Cliente *memoria[], int quantos);
void teste(Cliente *cliente);
void substituiMenorRegistro(Cliente *cliente[], int codigo, FILE *arquivo, long posicao);
Cliente* receberCliente(FILE *arquivo, long posicao);

