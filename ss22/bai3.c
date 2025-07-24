#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc node của danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Thêm node vào danh sách
void addToList(Node** graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// In danh sách kề
void printAdjList(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

// Giải phóng bộ nhớ
void freeGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

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

    // Khởi tạo danh sách kề
    Node** adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    // Chuyển từ ma trận kề sang danh sách kề
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) { // duyệt ngược để in theo thứ tự tăng dần
            if (matrix[i][j] == 1) {
                addToList(adjList, i, j);
            }
        }
    }

    // In danh sách kề
    printAdjList(adjList, n);

    // Giải phóng bộ nhớ
    freeGraph(adjList, n);

    return 0;
}
