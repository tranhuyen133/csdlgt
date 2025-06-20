#include <stdio.h>

int main() {
    int arr[100];
    int n, i, position, value;

    printf("Nhap so phan tu(0<n<=100): ");
    scanf("%d", &n);

    printf("Nhap %d phan tu :\n: ",n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri muon sua ",n);
    scanf("%d", &position);
    printf("Nhap gia tri moi ");
    scanf("%d", &value);

    if (position >= 0 && position < n) {
        arr[position] = value;

        printf("Mnag sau khi cap nhat ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }else {
        printf("vị trí khong hop le\n ");
    }
    return 0;
}