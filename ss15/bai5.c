#include <stdio.h>
#include <stdbool.h>

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

bool isEmpty(Queue q) {
    return q.rear < q.front;
}

int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("queue is empty\n");
        return -1;
    }
    return q->array[q->front++];
}

void printQueue(Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.array[i]);
    }
    printf("\n");
}

int main() {
    Queue q1 = initQueue(5);
    dequeue(&q1);

    Queue q2 = initQueue(5);
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    q2.rear = 2;

    int val = dequeue(&q2);
    if (val != -1)
        printf("return value = %d;\n", val);

    printf("queue = {\n   array = [");
    for (int i = 0; i <= q2.rear; i++) {
        printf("%d", q2.array[i]);
        if (i < q2.rear) printf(", ");
    }
    printf("],\n   front = %d,\n   rear = %d,\n   capacity = %d\n}\n", q2.front, q2.rear, q2.capacity);

    return 0;
}
