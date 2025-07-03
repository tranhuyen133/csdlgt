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
        printf("data: %d\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Node* temp;

    for (int i = 5; i >= 1; i--) {
        temp = createNode(i);
        temp->next = head;
        head = temp;
    }

    printList(head);

    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
