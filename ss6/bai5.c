#include <stdio.h>

int timMax(int a[],int n) {
    if (n==1) return a[0];
    int maxConLai = timMax(a,n-1);
    return (a[n - 1] > maxConLai) ? a[n - 1] : maxConLai;
}
int timMin(int a[],int n) {
    if (n==1) return a[0];
    int minConLai = timMin(a,n-1);
    return (a[n - 1] < minConLai) ? a[n - 1] : minConLai;
}
int main() {
    int a[100], n;
    printf("nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0) {
        printf("khong hop le");
        return 0;
    }

    printf("nhap %d phan tu \n",n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] =", i);
        scanf("%d", &a[i]);


    }
    int max=timMax(a,n);
    int min=timMin(a,n);
    printf("gia tri lon nhat :%d \n",max);
    printf("gia tri be nhat :%d \n",min);

    return 0;
}