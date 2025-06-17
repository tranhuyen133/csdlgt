#include <stdio.h>

int main() {
    int n, i, x;
    int arr[100];

    printf("Nhap so phan tu (0 < n <= 100): ");
    scanf("%d", &n);

    printf("Nhap %d phan tu: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap số cần đếm");
    scanf("%d", &x);

    int count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;

        }
    }
    printf("Số %d xuat hien %d lan trong mang \n ",x, count);

    return 0;
}