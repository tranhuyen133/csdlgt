#include <stdio.h>

int tongChuSo(int n) {
    if (n==0) return 0;
    return n % 10 + tongChuSo(n/10);
}
int main() {
    int n;
    printf("nhap so nguyen duong");
    scanf("%d", &n);

    if (n <= 0) {
        printf("khong hop le");

    }else {
        int tong = tongChuSo(n);
        printf("tong cac chu so:%d", tong);
    }
    return 0;
}