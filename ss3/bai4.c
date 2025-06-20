#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int **a;
    int max,min;

    printf("Nhap so hang (0 < rows < 1000)");
    scanf("%d",&rows);

    printf("Nhap so cot (0 < cols < 1000)");
    scanf("%d",&cols);

    if (rows<=0 || cols<=0 || rows>=1000 || cols>=1000 ) {
        printf("Kich thuoc khong hop le\n");
        return 1;
    }
    a = (int**)malloc(rows*sizeof(int*));
    for (int i=0;i<rows;i++) {
        a[i] = (int*)malloc(cols*sizeof(int));

    }
    printf("Nhap cac phan tu\n");
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);

            if ( i == 0 && j == 0) {
                max = a[i][j];
                min = a[i][j];

            }else {
                if (a[i][j] > max) max = a[i][j];
                if (a[i][j] < min) min = a[i][j];
            }
        }
    }
    printf("max = %d\n",max);
    printf("min = %d\n",min);

    for (int i=0;i<rows;i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
