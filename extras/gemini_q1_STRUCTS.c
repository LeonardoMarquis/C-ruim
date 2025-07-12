#include <stdio.h>
#define x 3
#define F 10
typedef struct{
    char nome[50];
    int matricula;
    float notas[x];
    float media;
}tAluno;


void preencherAluno(tAluno *a, int matrs[], int *quant){
    int matri_try, i;

    if(*quant == 10){
        printf("\nMAX CADASTRADOS");
        return;
    } 
    printf("\n-----------------------");
    printf("\nDADOS DO ALUNO: ");
    printf("\nMATRICULA: ");
    scanf("%d", &matri_try);

    for(i=0; i<F; i++){
        if(matri_try == matrs[i]){
            printf("\nJA TEM ALGUEM USANDO ESSA MATRICULA");
            return;
        }
    }
    (*a).matricula = matri_try;

    printf("\nNOME: ");
    getchar();
    scanf("%[^\n]", (*a).nome);

    for(i=0; i<x; i++){
        printf("\nNOTA %d: ", i +1);
        scanf("%f", &(*a).notas[i]);
    }


    *quant += 1;
}

void calcularMedia(tAluno *a){
    float doing_media = 0;
    int i;
    for(i=0; i<x; i++){
        doing_media += (*a).notas[i];
    }
    doing_media = (float) doing_media/x;

    (*a).media = doing_media;

}

void imprimirAluno(const tAluno *a){
    int i;
    printf("\n-----------------------");
    printf("\nDADOS DO ALUNO: ");
    printf("\nNOME: %s", (*a).nome);
    printf("\nMATRICULA: %d", (*a).matricula);
    for(i=0; i<x; i++){
        printf("\nNOTA %d: %f", i+1, (*a).notas[i]);
    }
    printf("\nMEDIA: %f", (*a).media);
}

int main(){
    tAluno aluno1;          // nessa questao eu nao quis colocar alunos dentro de um vetor com eles, aqui é simples
    int matrs[F];          // vou guardar as matriculas que ja estao cadastradas. 
    int quant;                  // quantos ja foram cadastrados
    preencherAluno(&aluno1, matrs, &quant);
    calcularMedia(&aluno1);
    imprimirAluno(&aluno1);


    return 0;
}