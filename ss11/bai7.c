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

Node* themTaiViTri(Node* head, int value, int pos) {
    Node* newNode = taoNode(value);
    if (pos <= 0 || head == NULL) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void inDanhSach(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
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

    inDanhSach(head);

    int value, pos;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &pos);

    head = themTaiViTri(head, value, pos);
    inDanhSach(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
