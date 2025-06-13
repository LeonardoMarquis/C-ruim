#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define n 200
typedef struct{
    int dia;
    int mes;
}tData;
typedef struct{
    char nome[80];
    char email[80];
    tData niver;
}tPessoa;

void cadastrar(tPessoa vet[], int *quant){
    if (*quant>= n){
        printf("\nLISTA CHEIA!\n");
        return;
    }

    printf("\nNome: \n");
    scanf(" %[^\n]", vet[*quant].nome);

    printf("\nEmail: \n");
    scanf(" %[^\n]", vet[*quant].email);

    printf("\nDia Nascimento: \n");
    scanf("%d", &vet[*quant].niver.dia);

    printf("\nMes Nascimento: \n");
    scanf("%d", &vet[*quant].niver.mes);

    (*quant)++;
}

void localizar(tPessoa vet[], char email[]){
    int j;
    for (j=0; j<n; j++){
        if (strcmp(vet[j].email ,email) == 0){     // quando o strmctp entre dois vetores de char der 0 é porque eles sao iguais
            printf("\n------------------------------------------------------------------------");
            printf("\n DADOS: ");
            printf("\nNOME: %s", vet[j].nome);
            printf("\nEMAIL: %s", vet[j].email);
            printf("\nANIVERSARIO: %d / %d\n", vet[j].niver.dia, vet[j].niver.mes);
            printf("\n------------------------------------------------------------------------");
        }
    }
    if (j == n){
        printf("\n BUSCA ENCERRADA\n");
    }
    
}

void aniver(tPessoa vet[], int mes_ver){
    int j;
    for (j=0; j<n; j++){
        if (vet[j].niver.mes == mes_ver){     // quando o strmctp entre dois vetores de char der 0 é porque eles sao iguais
            printf("\n------------------------------------------------------------------------");
            printf("\n---------DADOS: ");
            printf("\nNOME: %s", vet[j].nome);
            printf("\nEMAIL: %s", vet[j].nome);
            printf("\nANIVERSARIO: %d / %d\n", vet[j].niver.dia, vet[j].niver.mes);
            printf("\n------------------------------------------------------------------------\n");
        }
    }
    if (j == n){
        printf("\n BUSCA ENCERRADA\n");
    }
    
}


int main(){
    int quant=0, opcao, mes_ver;
    char email_buscar[80];
    tPessoa vet[n];
    while (1){
        printf("\n 1-CADASTRAR \n 2-LOCALIZAR \n 3-ANIVERSARIANTES DO MES \n 0-SAIR\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        case 1:
            cadastrar(vet, &quant);
            break;
        case 2:
            printf("\n EMAIL: ");
            scanf("%s", email_buscar);
            localizar(vet, email_buscar);
            break;
        case 3:
            printf("\n MES: ");
            scanf("%d", &mes_ver);
            aniver(vet, mes_ver);
            break;
        case 0:
            printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
            printf("\n ENCCERRANDO \n");
            printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
            return 0;

        default:
            printf("\n INVALIDO!!!!\n");
        }

    }
    

    return 0;
}