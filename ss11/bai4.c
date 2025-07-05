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

int tinhDoDai(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
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

    int dodai = tinhDoDai(head);
    printf("Danh sach lien ket co %d phan tu\n", dodai);

    Node* temp = node5;
    while (temp != NULL) {
        Node* prev = temp->prev;
        free(temp);
        temp = prev;
    }

    return 0;
}
