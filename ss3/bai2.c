#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *a;

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if ( n <= 0 || n>=1000) {
        printf("So luong phan tu khong hop le \n");
        return 1;
    }
    a = (int*)malloc(n*sizeof(int));
    if (a==NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d] ", i );
        scanf("%d", &a[i]);
    }

    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("max=%d\n",max);

    free(a);

    return 0;
}