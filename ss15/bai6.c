#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 31

typedef struct {
    char name[NAME_LEN];
} Customer;

typedef struct {
    Customer queue[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, char *name) {
    if (isFull(q)) {
        printf("Hàng đợi đầy\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    strncpy(q->queue[q->rear].name, name, NAME_LEN - 1);
    q->queue[q->rear].name[NAME_LEN - 1] = '\0';
    q->count++;
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng\n");
        return;
    }
    printf("Phục vụ khách: %s\n", q->queue[q->front].name);
    q->front = (q->front + 1) % MAX;
    q->count--;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng\n");
        return;
    }
    printf("Danh sách khách đang chờ:\n");
    int i, idx;
    for (i = 0, idx = q->front; i < q->count; i++) {
        printf("%d. %s\n", i + 1, q->queue[idx].name);
        idx = (idx + 1) % MAX;
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char name[NAME_LEN];

    do {
        printf("\n1. Thêm khách hàng\n2. Phục vụ\n3. Hiển thị danh sách\n4. Thoát\nChọn: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhập tên khách hàng: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                enqueue(&q, name);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Thoát chương trình\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ\n");
        }
    } while (choice != 4);

    return 0;
}
