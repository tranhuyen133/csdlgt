#include <stdio.h>

#define SIZE 4

// Hàm khởi tạo ma trận toàn 0
void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

// Hàm thêm cạnh cho đồ thị vô hướng
void addEdge(int graph[SIZE][SIZE], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Vì đồ thị vô hướng
}

// Hàm hiển thị ma trận kề
void printGraph(int graph[SIZE][SIZE]) {
    printf("[\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        for (int j = 0; j < SIZE; j++) {
            printf(" %d", graph[i][j]);
            if (j < SIZE - 1) printf(",");
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int graph[SIZE][SIZE];

    // Khởi tạo đồ thị rỗng
    initGraph(graph);

    printf("Ma trận ban đầu:\n");
    printGraph(graph);

    // Thêm cạnh theo đề bài
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("\nMa trận sau khi thêm cạnh:\n");
    printGraph(graph);

    return 0;
}
