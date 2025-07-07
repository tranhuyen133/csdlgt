#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}

void findMiddle(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int midIndex = count / 2;
    if (count % 2 == 0) midIndex++;

    temp = head;
    int index = 1;
    while (index < midIndex) {
        temp = temp->next;
        index++;
    }

    printf("Node %d: %d\n", midIndex, temp->data);
}

int main() {
    Node* head = NULL;

    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);


    printList(head);
    findMiddle(head);

    return 0;
}
