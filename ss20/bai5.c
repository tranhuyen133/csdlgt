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

// Hàm trả về giá trị lớn nhất trong cây nhị phân
int findMax(Node* root) {
    if (root == NULL)
        return -999999; // Giá trị nhỏ rất nhỏ, giả định cây không chứa giá trị nhỏ hơn

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    int max = root->data;
    if (maxLeft > max) max = maxLeft;
    if (maxRight > max) max = maxRight;

    return max;
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

        → Giá trị lớn nhất là 5
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    int maxValue = findMax(root);
    printf("Max value: %d\n", maxValue);

    return 0;
}
