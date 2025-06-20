#include <stdio.h>
int main() {
    int arr[100];
    int n, i, position;

    printf("Nhap phan tu(0<n<=100): ");
    scanf("%d", &n);

    printf("Nhap 5D phan tu: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri muon xoa",n);
    scanf("%d", &position);

    if (position >= 0 && position < n) {
        for (i = position; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Mang sau khi xoa\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }else {
        printf("Khong hop le\n");
    }
    return 0;
}