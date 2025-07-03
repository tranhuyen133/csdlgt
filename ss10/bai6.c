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

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    int index = 1;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        index++;
    }
    printf("Node %d: %d\n", index, slow->data);
}

int main() {
    Node* head = NULL;
    int arr[] = {6, 1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = n - 1; i >= 0; i--) {
        Node* newNode = createNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }

    printList(head);
    findMiddle(head);

    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
