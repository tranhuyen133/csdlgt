#include <stdio.h>

void chuyenDia(int n, char cotNguon, char cotTrungGian, char cotDich) {
    if (n==1) {
        printf("dia 1 di chuyen tu %c sang %c \n ", cotNguon, cotDich);
        return;
    }
    chuyenDia(n-1, cotNguon, cotDich, cotTrungGian);
    printf("Dia %d di chuyen tu %c sang %c\n2",n,cotNguon,cotDich);
    chuyenDia(n-1, cotNguon, cotTrungGian, cotDich);
    ;
}
int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);

    if (n<=0) {
        printf("khong hop le");
    }else {
        chuyenDia(n,'A','B','C');
    }
    return 0;
}