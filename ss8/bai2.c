#include <stdio.h>

int binarySearch(int a[], int left, int right, int value) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == value)
            return mid; // tìm thấy
        else if (a[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // không tìm thấy
}

int main() {
    int n, search, a[1000];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu (da sap xep tang dan):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int result = binarySearch(a, 0, n - 1, search);

    if (result != -1) {
        printf("phan tu vi tri thu %d\n", result + 1); // đánh số từ 1
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}
