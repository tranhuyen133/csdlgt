#include <stdio.h>
#include <stdlib.h>

int main() {
    int n ;
    int *a;
    int tong = 0, dem = 0;
    float trungBinh;

    printf("Nhap so luong phan tu ( 0 < n < 1000):");
    scanf("%d", &n);

    if (n<=0 || n>=1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    a = (int*)malloc(n*sizeof(int));
    if (a==NULL) {
        printf("khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d",i+1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            tong = tong + a[i];
            dem++;
        }
    }

    if (dem==0) {
        trungBinh = 0;
    }else {
        trungBinh = (float)tong/dem;
    }
    printf("average = %.0f\n",trungBinh);

    free(a);

    return 0;

}