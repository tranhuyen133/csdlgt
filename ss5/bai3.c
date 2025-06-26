#include <stdio.h>

int giaiThua(int n) {
    if (n == 1)
        return 1;
    else
        return n * giaiThua(n-1);

}
int main() {
    int n;
    printf("nhap so nguyen duong n ");
    scanf("%d",&n);

    if (n<=0) {
        printf("khong hop le");
    }else {
        int kq = giaiThua(n);
        printf("giai thua cua %d la %d",n, kq);
    }
    return 0;
}