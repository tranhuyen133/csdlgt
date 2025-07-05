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

Node* xoaTaiViTri(Node* head, int pos) {
    if (head == NULL || pos < 0) return head;
    Node* temp = head;
    if (pos == 0) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 0; i < pos && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return head;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
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

    int pos;
    printf("position: ");
    scanf("%d", &pos);

    head = xoaTaiViTri(head, pos);
    inDanhSach(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
