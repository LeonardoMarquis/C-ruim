/*
#include <stdio.h>
typedef struct{
    int num; //numerador
    int den; //denomindaor
}tFracao;


int mdc(int n1, int n2){
    while (n2 != 0){
        int resto = n1%n2;
        n1 = n2;
        n2 = resto;
    }
    return n1;  //ir dividindo ate o n1 virar o numero mdc, isso ai é o aloritmo euclidiano para fazer mdc
}


tFracao soma(int num1, int den1, int num2, int den2){
    int num_final, den_final;
    //usarei a formula de borboleta, a/b + a/d = (a*d + c*b) /b*d 
    num_final = num1 * den2 + num2 * den1;
    den_final = den1 * den2;


    //simplificando a fracao
    int mdc_deles = mdc(num_final, den_final);
    num_final = num_final/mdc_deles;
    den_final = den_final/mdc_deles;


    tFracao res = {num_final, den_final};
    return res;
}

tFracao subtracao(int num1, int den1, int num2, int den2){
    int num_final, den_final;
    //usarei a formula de borboleta, a/b - a/d = (a*d - c*b) /b*d 
    num_final = num1 * den2 - num2 * den1;
    den_final = den1 * den2;


    //simplificando a fracao
    int mdc_deles = mdc(num_final, den_final);
    num_final = num_final/mdc_deles;
    den_final = den_final/mdc_deles;

    tFracao res = {num_final, den_final};
    return res;
}
tFracao multiplicar(int num1, int den1, int num2, int den2){
    int num_final, den_final;

    num_final = num1 * num2;
    den_final = den1 * den2;

    tFracao res = {num_final, den_final};
    return res;
}

tFracao dividir(int num1, int den1, int num2, int den2){
    int num_final, den_final;

    num_final = num1 * den2;
    den_final = den1 * num2;

    tFracao res = {num_final, den_final};
    return res;
}


int main(){
    int continuar = 1, operacao;
    tFracao fracao1, fracao2, res;
    
    while(continuar == 1){
        printf("FRACAO 1");
        printf("\nNumerador ");
        scanf("%d", &fracao1.num);
        printf("\nDenominador ");
        scanf("%d", &fracao1.den);
        
        printf("\n 1 SOMAR \n 2 SUBTRAIR \n 3 MULTIPLICAR \n 4 DIVIDIR\n");
        scanf("%d", &operacao);

        printf("\nFRACAO 2");
        printf("\nNumerador ");
        scanf("%d", &fracao2.num);
        printf("\nDenominador ");
        scanf("%d", &fracao2.den);
        
        if (operacao == 1){
            res = soma(fracao1.num, fracao1.den, fracao2.num, fracao2.den);
            printf("\nRESULTADO: %d / %d", res.num, res.den);
        }

        if (operacao == 2){
            res = subtracao(fracao1.num, fracao1.den, fracao2.num, fracao2.den);
            printf("\nRESULTADO: %d / %d", res.num, res.den);
        }
        if (operacao == 3){
            res = multiplicar(fracao1.num, fracao1.den, fracao2.num, fracao2.den);
            printf("\nRESULTADO: %d / %d", res.num, res.den);
        }
        if (operacao == 4){
            res = dividir(fracao1.num, fracao1.den, fracao2.num, fracao2.den);
            printf("\nRESULTADO: %d / %d", res.num, res.den);
        }

        
        
        printf("\nContinuar? 1 or 0\n");
        scanf("%d", &continuar);
        if (continuar == 0){
            printf("\n ENCERRADO");
            break;
        }
    }
    return 0;
}
*/


#include <stdio.h>
# define n 2
typedef struct{
    int dia;
    int mes;
}tData;

typedef struct{
    char nome[80];
    char email[80];
    tData niver;
}tPessoa;

int main(){
    int i, mes_verify, j;
    tPessoa lista[n];

    for (i = 0; i<n; i++){
        printf("\nNome: \n");
        scanf("%s", &lista[i].nome);
        printf("\nEmail: \n");
        scanf("%s", &lista[i].email);
        printf("\nAniversario: \n");
        scanf("%d %d", &lista[i].niver.dia, &lista[i].niver.mes);
    }

    while (1)
    {
        printf("\n---------------------\nMES PARA VERIFICAR: \n--------------------\n");
        scanf("%d", &mes_verify);

        if (mes_verify == 0){
            break;
        }
        for(j = 0; j<n; j++){
            if(lista[j].niver.mes == mes_verify){
                printf("%s \n %s \n %d %d", lista[j].nome, lista[j].email, lista[j].niver.dia, lista[j].niver.mes);
            }
        }
    }
    


    return 0;
}
