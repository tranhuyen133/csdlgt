#include <stdio.h>

int fibonacci(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    int n, arr[100];

    printf("nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <=0 || n>100) {
        printf("input khong hop le:\n ");
        return 1;
    }
    printf("mang %d so Fibonanci dau tien : \n [",n);
    for (int i = 0; i < n; i++) {
        arr[i] = fibonacci(i);
        printf("%d ",arr[i]);
        if (i<n-1) printf(" ");
    }
    printf("]\n");
    return 0;

}