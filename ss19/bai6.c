#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo một node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàng đợi đơn giản cho con trỏ đến node
typedef struct Queue {
    Node** items;
    int front;
    int rear;
    int capacity;
} Queue;

// Tạo hàng đợi
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (Node**)malloc(sizeof(Node*) * capacity);
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

// Thêm vào hàng đợi
void enqueue(Queue* q, Node* node) {
    if (q->rear < q->capacity) {
        q->items[q->rear++] = node;
    }
}

// Lấy phần tử ra khỏi hàng đợi
Node* dequeue(Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->items[q->front++];
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Tìm kiếm theo chiều rộng (BFS)
int searchBFS(Node* root, int target) {
    if (root == NULL) return 0;
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == target) return 1;
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    return 0;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->right = createNode(4);

    int findValue = 3;

    printf("Tìm giá trị %d trong cây (BFS):\n", findValue);
    if (searchBFS(root, findValue))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
