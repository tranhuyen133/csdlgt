#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Định nghĩa hàng đợi
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Hàm tạo node mới từ input người dùng
Node* createNode() {
    int value;
    printf("Nhap gia tri so nguyen: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào hàng đợi
void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Hàm hiển thị hàng đợi
void displayQueue(Queue q) {
    Node* temp = q.front;
    printf("queue = {\n  front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (q.rear != NULL)
        printf("  rear->%d->NULL\n", q.rear->data);
    else
        printf("  rear->NULL\n");

    printf("},\n");
}

// Hàm main kiểm tra chương trình
int main() {
    Queue q;
    initQueue(&q);

    // Hiển thị hàng đợi ban đầu
    displayQueue(q);

    // Thêm phần tử vào hàng đợi
    enqueue(&q);  // Nhập 1 số
    displayQueue(q);

    enqueue(&q);  // Nhập thêm
    enqueue(&q);
    enqueue(&q);
    displayQueue(q);

    enqueue(&q);  // Nhập thêm nữa
    displayQueue(q);

    return 0;
}
