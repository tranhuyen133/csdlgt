#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Thêm vào danh sách kề
void addEdge(Node* graph[], int u, int v) {
    Node* node = createNode(v);
    node->next = graph[u];
    graph[u] = node;

    node = createNode(u);
    node->next = graph[v];
    graph[v] = node;
}

// DFS đệ quy
void DFS(Node* graph[], int v, int visited[]) {
    printf("%d ", v);
    visited[v] = 1;

    Node* temp = graph[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    Node* graph[MAX] = {NULL};  // Danh sách kề

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(graph, u, w);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    int visited[MAX] = {0};

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(graph, start, visited);
    printf("\n");

    // Giải phóng bộ nhớ
    for (int i = 0; i < v; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
