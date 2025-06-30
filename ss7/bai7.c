#include <stdio.h>

void sapXepPhanLop(int a[], int n) {
    int am[1000], duong[1000], zero[1000];
    int demAm = 0, demDuong = 0, demZero = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            am[demAm++] = a[i];
        else if (a[i] == 0)
            zero[demZero++] = a[i];
        else
            duong[demDuong++] = a[i];
    }

    int idx = 0;
    for (int i = 0; i < demAm; i++)
        a[idx++] = am[i];
    for (int i = 0; i < demZero; i++)
        a[idx++] = zero[i];
    for (int i = 0; i < demDuong; i++)
        a[idx++] = duong[i];
}

int main() {
    int n, a[1000];

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

    printf("before = [");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    sapXepPhanLop(a, n);

    printf("after = [");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
