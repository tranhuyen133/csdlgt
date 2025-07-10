#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 31

typedef struct {
    char name[NAME_LEN];
    int age;
} Customer;

typedef struct {
    Customer data[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue *q, Customer c) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = c;
    q->count++;
}

Customer dequeue(Queue *q) {
    Customer c = {"", -1};
    if (isEmpty(q)) return c;
    c = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return c;
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    Customer c;

    do {
        printf("\n1. Thêm khách\n2. Phục vụ khách\n3. Thoát\nChọn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập tên: ");
                fgets(c.name, NAME_LEN, stdin);
                c.name[strcspn(c.name, "\n")] = '\0';
                printf("Nhập tuổi: ");
                scanf("%d", &c.age);
                getchar();
                if (c.age >= 60)
                    enqueue(&queueOld, c);
                else
                    enqueue(&queueNormal, c);
                break;

            case 2:
                if (!isEmpty(&queueOld)) {
                    c = dequeue(&queueOld);
                    printf("Phục vụ (ưu tiên): %s (%d tuổi)\n", c.name, c.age);
                } else if (!isEmpty(&queueNormal)) {
                    c = dequeue(&queueNormal);
                    printf("Phục vụ: %s (%d tuổi)\n", c.name, c.age);
                } else {
                    printf("Không có khách nào đang chờ\n");
                }
                break;

            case 3:
                printf("Kết thúc phiên làm việc.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ\n");
        }
    } while (choice != 3);

    return 0;
}
