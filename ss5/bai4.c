#include <stdio.h>

int tinhTong(int a, int b) {
    if (a ==b) {
        return a;
    } else {
        return a + tinhTong(a + 1, b);
    }

}
int main() {
    int firstNum, secondNum;
    printf("nhap 2 so nguyen duong n ");
    scanf("%d %d",&firstNum,&secondNum);

    if (firstNum<=0 || secondNum <=0 || firstNum>secondNum) {
        printf("khong hop le\n");
    }else {
        int tong = tinhTong(firstNum, secondNum);
        printf("Tong tu %d den %d la: %d\n",firstNum,secondNum,tong);
    }
    return 0;
}