#include<stdio.h>
int main() {
    int n,i;
    int arr[100];

    printf("Nhap so phan tu (0 < n <= 100: ");
    scanf("%d", &n);

    printf("Nhap so phan tu cua mang:\n ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for ( i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat la : %d\n ",max);

    return 0;
}