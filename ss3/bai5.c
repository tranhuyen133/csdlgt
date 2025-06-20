#include <stdio.h>
#include <stdlib.h>
int main() {
    int rows = 0, cols = 0;
    int **a;
    int tongCheoChinh = 0 , tongCheoPhu = 0 ;

    printf("Nhap so hang (0 < cols < 1000)");
    scanf("%d",&rows);

    printf("Nhap so cot (0 < cols < 1000)");
    scanf("%d",&cols);

    if (rows<=0 || cols<=0 || rows>=1000 || cols>=1000 ) {
        printf("Kich thuoc khong hop le\n");
        return 1;
    }
    a = (int **)malloc(rows*sizeof(int *));
    for (int i=0;i<rows;i++) {
        a[i] = (int *)malloc(cols*sizeof(int));
    }
    printf("Nhap cac phan tu cua mang\n");
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    //tinh tổng duong cheo chinh và phụ
    //Lap so nho giữa rows và cols
    int minSize = (rows < cols) ? rows : cols;

    for (int i=0; i < minSize;i++) {

        tongCheoChinh += a[i][i];
        tongCheoPhu += a[i][cols-1-i];
    }
    printf ("tong duong cheo chinh : %d\n",tongCheoChinh);
    printf ("tong duong cheo phu : %d\n",tongCheoPhu);

    for (int i=0;i<rows;i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}