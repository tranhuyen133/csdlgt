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

Node* deleteValue(Node* head, int value) {
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    int values[] = {5, 4, 3, 5, 2, 1, 5};
    for (int i = 6; i >= 0; i--) {
        Node* newNode = createNode(values[i]);
        newNode->next = head;
        head = newNode;
    }

    printList(head);

    int x;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &x);

    head = deleteValue(head, x);

    printList(head);

    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
