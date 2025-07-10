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

int main() {
    Queue q1 = initQueue(5);
    if (isEmpty(q1))
        printf("true\n");
    else
        printf("false\n");

    Queue q2 = initQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    if (isEmpty(q2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
