#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Tạo một node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Duyệt cây theo thứ tự trước (tiền tự) để kiểm tra
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Tìm và trả về nút cuối cùng trong cây + cha của nó
void findDeepestNode(Node* root, Node** deepest, Node** parent) {
    if (!root) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    Node* temp;
    *parent = NULL;

    while (front < rear) {
        temp = queue[front++];
        if (temp->left) {
            *parent = temp;
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            *parent = temp;
            queue[rear++] = temp->right;
        }
    }

    *deepest = temp;
}

// Xóa nút có giá trị cần tìm trong cây
void deleteNode(Node* root, int value) {
    if (root == NULL) {
        printf("Cay rong.\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            free(root);
            root = NULL;
            printf("Da xoa %d\n", value);
        } else {
            printf("Khong tim thay %d trong cay.\n", value);
        }
        return;
    }

    Node* nodeToDelete = NULL;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    // Tìm node có giá trị cần xóa
    while (front < rear) {
        Node* temp = queue[front++];

        if (temp->data == value) nodeToDelete = temp;

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (nodeToDelete) {
        Node* deepest;
        Node* parent;
        findDeepestNode(root, &deepest, &parent);

        // Ghi đè dữ liệu
        nodeToDelete->data = deepest->data;

        // Xóa deepest node
        if (parent->left == deepest)
            parent->left = NULL;
        else if (parent->right == deepest)
            parent->right = NULL;

        free(deepest);
        printf("Da xoa %d\n", value);
    } else {
        printf("Khong tim thay %d trong cay.\n", value);
    }
}

// Test mẫu
int main() {
    // Cây mẫu
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Cay truoc khi xoa:\n");
    preorder(root);
    printf("\n");

    int value = 3;
    printf("deleteValue: %d\n", value);
    deleteNode(root, value);

    printf("Cay sau khi xoa:\n");
    preorder(root);
    printf("\n");

    return 0;
}
