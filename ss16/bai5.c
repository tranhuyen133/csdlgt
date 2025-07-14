#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

Node* createNode() {
    int value;
    printf("Nhap gia tri so nguyen: ");
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue q) {
    Node* temp = q.front;
    printf("queue = {\n  front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (q.rear)
        printf("  rear->%d->NULL\n", q.rear->data);
    else
        printf("  rear->NULL\n");
    printf("},\n\n");
}

int main() {
    Queue q;
    initQueue(&q);

    displayQueue(q);
    dequeue(&q);

    enqueue(&q); // nhập 1
    enqueue(&q); // nhập 2
    enqueue(&q); // nhập 5

    displayQueue(q);
    dequeue(&q);
    displayQueue(q);

    return 0;
}
