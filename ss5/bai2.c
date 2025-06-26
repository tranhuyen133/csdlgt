# include <stdio.h>

int tinhTong(int n) {
    if (n==1)
        return 1;
    else
        return tinhTong(n-1);

}
int main() {
    int n;

    printf("nhao so nguyen duong n ");
    scanf("%d",&n);

    if (n<=0) {
        printf("khong hop le");
    }else {
        int tong=tinhTong(n);
        printf("tong tu 1 den %d la :%d",n, tong);
    }
    return 0;
}
