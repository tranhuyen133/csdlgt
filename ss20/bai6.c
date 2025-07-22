//
// Created by admin on 22/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Tìm tầng (level) của node có giá trị value
int findLevel(Node* root, int value, int level) {
    if (root == NULL)
        return -1;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1)
        return leftLevel;

    return findLevel(root->right, value, level + 1);
}

// Hàm gọi chính
int getNodeLevel(Node* root, int value) {
    return findLevel(root, value, 0); // tầng gốc là 0
}

// -------------------------
// Ví dụ sử dụng
int main() {
    /*
        Cây ví dụ:
               1
              / \
             2   3
            / \
           4   5
    */

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int value = 3;
    int level = getNodeLevel(root, value);
    if (level != -1)
        printf("Node level: %d\n", level);
    else
        printf("Node not found.\n");

    return 0;
}
