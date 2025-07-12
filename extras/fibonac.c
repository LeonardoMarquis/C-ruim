#include <stdio.h>

int fib(int n) {
    int t1 = 1, t2 = 1;
    int prox;
    int i;

    if (n <= 2) return 1;

    for (i = 3; i <= n; i++) {
        prox = t1 + t2;
        t1 = t2;
        t2 = prox;
    }

    return prox;
}

int main() {
    int n;
    printf("Digite o termo n da sequência de Fibonacci: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fib(n));

    return 0;
}
