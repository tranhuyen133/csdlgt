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

int main() {
    Node* head = taoNode(10);
    Node* node2 = taoNode(20);
    Node* node3 = taoNode(30);
    Node* node4 = taoNode(40);
    Node* node5 = taoNode(50);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = node5;
    while (temp != NULL) {
        Node* prev = temp->prev;
        free(temp);
        temp = prev;
    }

    return 0;
}
