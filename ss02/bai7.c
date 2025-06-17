#include <stdio.h>

int main() {
    int arr[100];
    int n, sum;
    int found = 0;

    printf("nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Nhap tong can tim: ");
    scanf("%d", &sum);
    for (int i = 0; i < n - 1 && !found; i++) {
        for (int j = i + 1; j < n && !found; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("tim thay cap :%d,%d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("khong tim thay\n");

    }
    return 0;
}