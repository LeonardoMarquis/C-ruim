#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200
typedef struct{
    int dia;
    int mes;
}tData;
typedef struct{
    char nome[80];
    char email[80];
    tData niver;
}tPessoa;

typedef struct{
    tPessoa conj[MAX];
    int quant;
}tConjunto;

void cadastrar(tConjunto grupao){
    if (grupao.quant>= MAX){
        printf("\nLISTA CHEIA!\n");
        return;
    }

    printf("\nNome: \n");
    scanf(" %[^\n]", grupao.conj[grupao.quant].nome);

    printf("\nEmail: \n");
    scanf(" %[^\n]", grupao.conj[grupao.quant].email);

    printf("\nDia Nascimento: \n");
    scanf("%d", &grupao.conj[grupao.quant].niver.dia);

    printf("\nMes Nascimento: \n");
    scanf("%d", &grupao.conj[grupao.quant].niver.mes);

    (grupao.quant)++;
}

void localizar(tConjunto grupao, char email[]){
    int j;
    for (j=0; j<MAX; j++){
        if (strcmp(grupao.conj[j].email ,email) == 0){     // quando o strmctp entre dois grupao.conjores de char der 0 é porque eles sao iguais
            printf("\n------------------------------------------------------------------------");
            printf("\n DADOS: ");
            printf("\nNOME: %s", grupao.conj[j].nome);
            printf("\nEMAIL: %s", grupao.conj[j].email);
            printf("\nANIVERSARIO: %d / %d\n", grupao.conj[j].niver.dia, grupao.conj[j].niver.mes);
            printf("\n------------------------------------------------------------------------");
        }
    }
    if (j == MAX){
        printf("\n BUSCA ENCERRADA\n");
    }
    
}

void aniver(tConjunto grupao, int mes_ver){
    int j;
    for (j=0; j<MAX; j++){
        if (grupao.conj[j].niver.mes == mes_ver){     // quando o strmctp entre dois grupao.conjores de char der 0 é porque eles sao iguais
            printf("\n------------------------------------------------------------------------");
            printf("\n---------DADOS: ");
            printf("\nNOME: %s", grupao.conj[j].nome);
            printf("\nEMAIL: %s", grupao.conj[j].nome);
            printf("\nANIVERSARIO: %d / %d\n", grupao.conj[j].niver.dia, grupao.conj[j].niver.mes);
            printf("\n------------------------------------------------------------------------\n");
        }
    }
    if (j == MAX){
        printf("\n BUSCA ENCERRADA\n");
    }
    
}


int main(){
    int opcao, mes_ver;
    char email_buscar[80];
    tConjunto grupao;
    grupao.quant = 0;

    while (1){
        printf("\n 1-CADASTRAR \n 2-LOCALIZAR \n 3-ANIVERSARIANTES DO MES \n 0-SAIR\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        case 1:
            cadastrar(grupao);
            break;
        case 2:
            printf("\n EMAIL: ");
            scanf("%s", email_buscar);
            localizar(grupao, email_buscar);
            break;
        case 3:
            printf("\n MES: ");
            scanf("%d", &mes_ver);
            aniver(grupao, mes_ver);
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



// EXCELENTE ISSO!!!, COLOCAR O CONTROLADOR DA QUANTIDADE DE USUARIOS CADASTRADOS DENTRO DO MEUS OBJETO COM A 
// LISTA ENORME ONDE QUERO CADASTRAR PESSOAS É MUITO MELHOR DO QUE DE OUTROS JEITOS. PORQUE AI 
// É SO PASSAR O MACROOBJETO COMO PARAMENTRO, E DENTRO DESSE MACROOBJETO TEM A LISTA ONDE VOU CADASTRAR OS OBJETOS
// PESSOAS E TEM TAMBEM O CONTROLADOR PARA DIZER EM QUAL POSICAO CADASTRAR AS PESSOAS.