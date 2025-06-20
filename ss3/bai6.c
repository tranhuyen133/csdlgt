#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr;

    printf("Nhap so luong phan tu ban dau(n) ");
    scanf("%d",&n);
    if (n<=0 || n>=1000) {
        printf("so luong phan tu khong hop le\n");
        return 1;
    }
    arr = (int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf(" khong hop le\n");
        return 1;

    }
    for (int i=0; i < n; i++) {
        printf("Nhap phan tu thu %d: ",i + 1);
        scanf("%d",&arr[i]);
    }

    printf("Nhap so luong phan tu muon them(m)");
    scanf("%d",&m);

    if (m<0 || (m+n)>1000) {
        printf("khong hop le\n");
        free(arr);
        return 1;
    }
    int *temp = (int*)realloc(arr, (n +m)*sizeof(int));
    if (temp==NULL) {
        printf("khong hop le\n");
        free(arr);
        return 1;

    }
    arr = temp;

    for (int i= n; i < m + n; i++) {
        printf("Nhap phan tu thu %d",i+1);
        scanf("%d",&arr[i]);
    }
    printf("mang sau khi them :");
    for (int i=0; i < m + n; i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}