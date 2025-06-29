#include <stdio.h>

int demSoCach(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return demSoCach(n - 1) + demSoCach(n - 2);
}

int main() {
    int n;
    printf("nhap so bậc của cau thang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hợp lệ\n");
    } else {
        int soCach = demSoCach(n);
        printf("so cach leo cau thang %d bac: %d\n", n, soCach);
    }

    return 0;
}
