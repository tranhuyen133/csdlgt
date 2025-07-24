#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int matrix[MAX][MAX];

    // Nhập ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int edgeCount = 0;

    // Duyệt ma trận kề, chỉ duyệt nửa tam giác trên
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    printf("%d\n", edgeCount);
    return 0;
}
