#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int value;
    printf("Nhập giá trị nguyên để tạo node: ");
    scanf("%d", &value);

    Node* node = createNode(value);

    printf("Node vừa tạo:\n");
    printf("Data: %d\n", node->data);
    printf("Left: %p\n", (void*)node->left);
    printf("Right: %p\n", (void*)node->right);

    free(node);
    return 0;
}
