#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = NULL;
    Node* temp;
    Node* tail = NULL;

    for (int i = 0; i < 5; i++) {
        int value;
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        temp = createNode(value);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    printf("Danh sach lien ket: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");

    while (head != NULL) {
        Node* next =*
