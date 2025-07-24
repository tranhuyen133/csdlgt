#include <stdio.h>
#include <stdlib.h>

//ham them canh vao do thi
void addEdge(int **graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // Vì đồ thị vô hướng
}

//ham in ma tran ke
void printGraph(int **graph,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n; // Số đỉnh
    scanf("%d", &n);

    // Cấp phát ma trận kề và khởi tạo 0
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)calloc(n, sizeof(int));
    }

    // Đọc cạnh cho đến khi hết dữ liệu đầu vào
    int u, v;
    while (scanf("%d %d", &u, &v) != EOF) {
        addEdge(graph, u, v);
    }
    // In ma trận kề
    printGraph(graph, n);

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}