#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

void inFibonaccinguoc(int n) {

    if (n <= 0) return;
    printf("%d", fibonacci(n - 1));
    inFibonaccinguoc(n - 1);

}

int main() {
    int n;
    printf("nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("khong hop le" );
    }else {
        printf("Day Fibonanci nguoc : ");
        inFibonaccinguoc(n);
        printf("\n");
    }
    return 0;

}