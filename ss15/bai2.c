#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

Queue initQueue(int cap) {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.capacity = cap;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

void printQueue(Queue q) {
    printf("queue = {\n");
    printf("  array = [");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i < q.rear) printf(", ");
    }
    printf("],\n");
    printf("  front = %d,\n", q.front);
    printf("  rear = %d,\n", q.rear);
    printf("  capacity = %d\n", q.capacity);
    printf("}\n");
}

int main() {
    Queue q = initQueue(5);
    printQueue(q);
    int value;
    for (int i = 0; i < 6; i++) {
        printf("Nhap gia tri: ");
        scanf("%d", &value);
        enqueue(&q, value);
        printQueue(q);
    }
    return 0;
}
