#include <stdio.h>

int main() {
    int rows, cols, k;
    int a[1000][1000];

    printf("Nhap so hang: ");
    scanf("%d", &rows);

    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("Kich thuoc khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Nhap chi so cot can sap xep (bat dau tu 0): ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("Chi so cot khong hop le\n");
        return 1;
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (a[i][k] > a[j][k]) {
                for (int m = 0; m < cols; m++) {
                    int temp = a[i][m];
                    a[i][m] = a[j][m];
                    a[j][m] = temp;
                }
            }
        }
    }

    printf("Mang sau khi sap xep cot %d tang dan:\n", k);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
