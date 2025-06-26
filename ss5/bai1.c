#include <stdio.h>

void inTu1DenN(int n) {
    if (n == 0) return;
    inTu1DenN(n - 1);
    printf("%d\n", n);

}

int main() {
    int n;
    printf("Nhap so nguyen duong n");
    scanf("%d", &n);

    if (n == 0) {
        printf("nhap so nguyen duong lon hon 0 \n");
    }else {
        printf("Cac so tu 1 den %d la :\n");
        inTu1DenN(n);


    }
    return 0;
}