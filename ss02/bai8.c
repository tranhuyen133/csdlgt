#include <stdio.h>
int main() {
    int arr[100];
    int n;

    printf("Nhap so phan tu : ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu lon hon cac phan tu ben sau no la : \n");
    for (int i = 0; i < n; i++) {
        int isLarger = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isLarger = 0;
                break;
            }
        }
        if (isLarger){
            printf("%d",arr[i]);
        }
    }
    return 0;
}