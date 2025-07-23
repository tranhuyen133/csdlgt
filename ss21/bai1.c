#include <stdio.h>

#define SIZE 3

// Hàm khởi tạo ma trận đồ thị
void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}


// Hàm thêm cạnh (vì đồ thị vô hướng nên thêm cả 2 chiều)
void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    // Trừ 1 vì mảng bắt đầu từ 0
    graph[firstNode - 1][secondNode - 1] = 1;
    graph[secondNode - 1][firstNode - 1] = 1;
}

// Hàm in ma trận đồ thị
void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE];

    // Khởi tạo đồ thị chưa có cạnh nào
    initGraph(graph);

    printf("Ban đầu:\n");
    printGraph(graph);

    // Thêm cạnh giữa nút 1 và nút 2
    addEdge(graph, 1, 2);

    printf("\nSau khi thêm cạnh giữa node 1 và 2:\n");
    printGraph(graph);

    return 0;
}
