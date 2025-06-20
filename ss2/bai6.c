#include <stdio.h>
int main() {
    int arr[100];
    int n, i, position ,value;

    printf("nhap phan tu(0<n<=100): ");
    scanf("%d", &n);

    printf("nhap phan tu: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap vi tri muon them");
    scanf("%d", &position);
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    if (position < 0 || position > n) {
        printf("Khong hop le\n");
        return 0;
    }
    for (i = n; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = value;
    n++;

    printf("Mang sau khi them\n: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}