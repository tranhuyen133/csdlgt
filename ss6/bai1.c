#include <stdio.h>

void inNhiPhan(int n) {
    if (n == 0) return;
    inNhiPhan(n/2);
    printf("%d", n%2);
}
int main() {
    int so;
    printf("nhap so nguyen duong");
    scanf("%d", &so);

    if (so <=0) {
        printf("khong hop le\n");
    }else {
        printf("dang nhi phan");
        inNhiPhan(so);

    }
    return 0;
}
