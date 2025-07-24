#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node trong danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Thêm node mới vào đầu danh sách
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh vào đồ thị vô hướng
void addEdge(Node** graph, int u, int v) {
    // Thêm v vào danh sách kề của u
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;

    // Thêm u vào danh sách kề của v
    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}

// In danh sách kề
void printGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
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

    // Khởi tạo danh sách kề
    Node** graph = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    int u, v;
    while (scanf("%d %d", &u, &v) != EOF) {
        addEdge(graph, u, v);
    }

    // In danh sách kề
    printGraph(graph, n);

    // Giải phóng bộ nhớ
    freeGraph(graph, n);

    return 0;
}
