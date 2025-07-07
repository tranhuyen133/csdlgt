#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void prepend(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void printListForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("data: %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    prepend(&head, 1);
    prepend(&head, 2);
    prepend(&head, 3);
    prepend(&head, 4);
    prepend(&head, 5);

    printListForward(head);
    return 0;
}
