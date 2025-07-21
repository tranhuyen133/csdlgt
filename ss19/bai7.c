#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node** items;
    int front;
    int rear;
    int capacity;
} Queue;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (Node**)malloc(sizeof(Node*) * capacity);
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < q->capacity) {
        q->items[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->items[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Hàm thêm phần tử vào cây nhị phân theo thứ tự từng tầng
void addNode(Node* root, int value) {
    if (root == NULL) return;
    Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(q, current->right);
        }
    }
}

// Hàm duyệt cây theo BFS để in toàn bộ giá trị
void printLevelOrder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    printf("\n");
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->right = createNode(4);

    int addValue = 6;
    printf("Cây trước khi thêm:\n");
    printLevelOrder(root);

    addNode(root, addValue);

    printf("Cây sau khi thêm giá trị %d:\n", addValue);
    printLevelOrder(root);

    return 0;
}
