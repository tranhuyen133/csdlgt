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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

Node* addLast(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;

    for (int i = 5; i >= 1; i--) {
        Node* newNode = createNode(i);
        newNode->next = head;
        head = newNode;
    }

    printList(head);

    int x;
    printf("Nhap so muon them cuoi danh sach: ");
    scanf("%d", &x);

    head = addLast(head, x);

    printList(head);

    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
