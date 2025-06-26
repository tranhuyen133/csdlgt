#include <stdio.h>
int tinhTongMang(int arr[],int n) {
    if (n==0)  return 0;
    return arr[n-1] + tinhTongMang(arr,n-1);
}

int main() {
    int n, arr[100];
    printf("Nhap so luong phan tu");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("khong hop le");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);

    }
    int tong = tinhTongMang(arr,n);
    printf("tinh tong trong mang la: %d\n",tong);
    return 0;
}