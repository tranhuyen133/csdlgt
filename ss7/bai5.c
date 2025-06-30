#include <stdio.h>

void quickSort(int a[], int low, int high) {
    if (low >= high) return;

    int pivot = a[(low + high) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(a, low, j);
    quickSort(a, i, high);
}

int main() {
    int n, i;
    int a[1000];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("before = [");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    quickSort(a, 0, n - 1);

    printf("after = [");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
