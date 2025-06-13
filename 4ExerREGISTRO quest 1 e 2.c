/*#include <stdio.h>

typedef struct{
    float x;
    float y;
} tPonto;

int main (){
    tPonto ponto1;

    while (1) {
        printf("PONTO X: ");
        scanf("%f", &ponto1.x);

        printf("PONTO Y: ");
        scanf("%f", &ponto1.y);

        if (ponto1.x == 0 && ponto1.y == 0) {
            break; // Sai do loop se os dois forem zero
        }

        printf("\nX: %f \nY: %f\n", ponto1.x, ponto1.y);
    }

    return 0;
}
*/


#include <stdio.h>
typedef struct{
    int num; //numerador
    int den; //denomindaor
}tFracao;

int mdc(int n1, int n2){
    while (n2 != 0)
    {
        int resto = n1%n2;
        n1 = n2;
        n2 = resto;
    }

    return n1;
}


int main(){
    int n, i;
    tFracao fracao;

    scanf("%d", &n);
    
    for (i = 0; i<n; i++){
        printf("\nNumerador");
        scanf("%d", &fracao.num);
        printf("\nDenominador");
        scanf("%d", &fracao.den);
        
        int mdc_num_e_den = mdc(fracao.num, fracao.den);

        fracao.num = fracao.num/mdc_num_e_den;
        fracao.den = fracao.den/mdc_num_e_den;

        printf("\n Result \n %d / %d", fracao.num, fracao.den);
        
    }
    return 0;
}









