#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* taoNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void themCuoi(Node** head, int data) {
    Node* newNode = taoNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void inDanhSach(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}

void doiChoCap(Node** head) {
    Node* current = *head;

    while (current != NULL && current->next != NULL) {
        Node* first = current;
        Node* second = current->next;

        int tmp = first->data;
        first->data = second->data;
        second->data = tmp;

        current = second->next;
    }
}

int main() {
    Node* head = NULL;

    themCuoi(&head, 1);
    themCuoi(&head, 2);
    themCuoi(&head, 3);
    themCuoi(&head, 4);
    themCuoi(&head, 5);

    printf("Before:\n");
    inDanhSach(head);

    doiChoCap(&head);

    printf("After:\n");
    inDanhSach(head);

    return 0;
}
