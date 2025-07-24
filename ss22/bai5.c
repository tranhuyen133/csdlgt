#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    int u[MAX], v[MAX]; // Mỗi cạnh gồm (u[i], v[i])
    printf("Nhap cac canh:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int visited[MAX] = {0}; // Đánh dấu các đỉnh đã kề

    for (int i = 0; i < m; i++) {
        if (u[i] == k) {
            visited[v[i]] = 1;
        } else if (v[i] == k) {
            visited[u[i]] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            count++;
        }
    }

    printf("So dinh ke voi %d la: %d\n", k, count);
    return 0;
}
