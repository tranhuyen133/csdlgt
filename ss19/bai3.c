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

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->right = createNode(4);

    printf("Duyệt cây theo Postorder:\n");
    postorderTraversal(root);

    return 0;
}
