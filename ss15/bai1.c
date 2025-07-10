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
    int n = 5;
    Queue q = initQueue(n);
    printQueue(q);
    return 0;
}
