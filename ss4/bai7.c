#include <stdio.h>

int main() {
    int n, arr[1000];

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

    int found = 0;

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - 1 - i]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - 1 - i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co phan tu doi xung\n");
    }

    return 0;
}
