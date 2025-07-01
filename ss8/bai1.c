#include <stdio.h>

int main() {
    int n, search, a[1000];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == search) {
            printf("Vi tri thu %d\n", i + 1);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}
