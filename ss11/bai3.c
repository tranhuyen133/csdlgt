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

int timKiem(Node* head, int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = taoNode(1);
    Node* node2 = taoNode(2);
    Node* node3 = taoNode(3);
    Node* node4 = taoNode(4);
    Node* node5 = taoNode(5);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    if (timKiem(head, x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    Node* temp = node5;
    while (temp != NULL) {
        Node* prev = temp->prev;
        free(temp);
        temp = prev;
    }

    return 0;
}
