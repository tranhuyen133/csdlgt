#include <stdio.h>

int main() {
    int n, i;
    int arr[100];

    printf("Nhap so phan tu (0<=n<=100): ");
    scanf("%d", &n);

    printf("Nhap %d phan tu :\n",n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n / 2; i++) {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;

    }
    printf("mang sau khi dao nguoc :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
