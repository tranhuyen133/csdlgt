#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
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

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Vi tri phan tu can tim la: %d\n", i); // Chỉ số đầu tiên tìm được
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu\n");
    }

    free(arr);
    return 0;
}
