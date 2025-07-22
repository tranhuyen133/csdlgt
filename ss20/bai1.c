#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một phần tử (nút) trong cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo phần tử mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // cấp phát bộ nhớ
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int input;
    printf("Nhập số nguyên để tạo nút: ");
    scanf("%d", &input);

    Node* root = createNode(input);  // Tạo nút gốc

    // In thông tin nút vừa tạo
    printf("\nNút vừa tạo:\n");
    printf("data: %d\n", root->data);
    printf("left: %p\n", (void*)root->left);
    printf("right: %p\n", (void*)root->right);

    // Giải phóng bộ nhớ
    free(root);
    return 0;
}
