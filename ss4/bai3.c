#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int minValue = arr[0];
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    printf("Chi so cua phan tu nho nhat dau tien la: %d\n", minIndex);

    free(arr);
    return 0;
}
