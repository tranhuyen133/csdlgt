#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *a;

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);

        if (n < 0) {
            printf("So luong khong duoc am\n");
        } else if (n == 0) {
            printf("So luong phan tu phai lon hon 0\n");
        } else if (n >= 1000) {
            printf("So luong qua lon (n < 1000)\n");
        }
    } while (n <= 0 || n >= 1000);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    int i = 0;
    do {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &a[i]);
        i++;
    } while (i < n);

    i = 0;
    do {
        printf("So thu %d = %d\n", i + 1, a[i]);
        i++;
    } while (i < n);

    free(a);

    return 0;
}
