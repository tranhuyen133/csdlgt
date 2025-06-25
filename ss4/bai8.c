#include <stdio.h>

int main() {
    int n, x, arr[1000];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int found = 0;
    printf("Vi tri xuat hien: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Phan tu khong co trong mang");
    }

    return 0;
}
