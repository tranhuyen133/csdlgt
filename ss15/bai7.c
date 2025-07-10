#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int val) {
    q->rear++;
    q->data[q->rear] = val;
}

bool checkIncreasingBy1(Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        if (q->data[i + 1] - q->data[i] != 1)
            return false;
    }
    return true;
}

int main() {
    Queue q;
    init(&q);
    int n, x;
    scanf("%d", &n);
    if (n <= 0 || n >= MAX) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }
    if (checkIncreasingBy1(&q))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
