#include <stdio.h>

typedef struct{
    double coeficiente;
    int expoente;
}Fator;

void derivar(Fator fator){
    Fator resultado;

    resultado.coeficiente = fator.coeficiente * fator.expoente;    
    resultado.expoente = fator.expoente - 1;

    printf("%.1lfx", resultado.coeficiente);

    if(resultado.expoente > 1){
        printf("^%d", resultado.expoente);
    }

    if(resultado.expoente > 1){
        printf(" + ");
    }

}

int main(){

    printf("qual o grau da funcao?\n");
    int grau;
    scanf("%d", &grau);

    if(grau == 0){
        printf("resultado : 0");
    }

    Fator fatores[grau];

    for(int cont = grau; cont > -1; cont--){
        printf("insira o coeficiente\n");
        scanf("%lf", &fatores[cont].coeficiente);
        fatores[cont].expoente = cont;
    }

    printf("\n\n\n\n\n");
    printf("a funcao: ");
    for(int cont = grau; cont > -1; cont--){
        printf("%.1lfx^%d + ", fatores[cont].coeficiente, cont);
    }

    printf("\ntem como derivada: ");

    for(int cont = grau; cont > 1; cont--){
        derivar(fatores[cont]);
    }

    printf(" + %.1lf", fatores[1].coeficiente);

    printf("\n\n\n\n");
    
    return 0;
}
