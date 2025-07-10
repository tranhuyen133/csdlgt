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

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
}

int main() {
    Queue q1 = initQueue(5);
    displayQueue(q1);

    Queue q2 = initQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    displayQueue(q2);

    return 0;
}
