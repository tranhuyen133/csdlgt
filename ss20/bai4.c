#include <stdio.h>
#include <stdlib.h>

// Cấu trúc nút cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm đếm số lá trong cây nhị phân
int countLeaves(Node* root) {
    if (root == NULL) return 0;

    // Nếu là lá (không có con trái & phải)
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Đệ quy đếm lá bên trái + phải
    return countLeaves(root->left) + countLeaves(root->right);
}

// Hàm chính để kiểm tra
int main() {
    /*
        Cây mẫu:
              1
             / \
            2   3
               / \
              4   5

        Lá là: 2, 4, 5 → có 3 lá
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    int numLeaves = countLeaves(root);
    printf("Number of leaves: %d\n", numLeaves);

    return 0;
}
