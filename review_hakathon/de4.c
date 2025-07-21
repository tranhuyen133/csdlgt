#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100

// Định nghĩa cấu trúc node stack
typedef struct Node {
    char url[MAX_URL];
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        strcpy(newNode->url, url);
        newNode->next = NULL;
    }
    return newNode;
}

// Hàm đẩy vào stack
void push(Node** top, char* url) {
    Node* newNode = createNode(url);
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return;
    }
    newNode->next = *top;
    *top = newNode;
}

// Hàm lấy phần tử trên cùng của stack
char* top(Node* stack) {
    if (stack == NULL) return NULL;
    return stack->url;
}

// Hàm pop khỏi stack
char* pop(Node** top) {
    if (*top == NULL) return NULL;
    Node* temp = *top;
    char* url = (char*)malloc(MAX_URL * sizeof(char));
    strcpy(url, temp->url);
    *top = (*top)->next;
    free(temp);
    return url;
}

// Hàm kiểm tra stack rỗng
int isEmpty(Node* stack) {
    return stack == NULL;
}

// Hàm giải phóng stack
void clearStack(Node** top) {
    while (!isEmpty(*top)) {
        Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

// ===============================
// Chương trình chính
int main() {
    Node* backStack = NULL;
    Node* forwardStack = NULL;
    char current[MAX_URL] = "Trang chủ";

    int choice;
    char url[MAX_URL];

    do {
        printf("\n========= LỊCH SỬ DUYỆT WEB =========\n");
        printf("1. Truy cập trang mới\n");
        printf("2. Quay lại (Back)\n");
        printf("3. Đi tới (Forward)\n");
        printf("4. Hiển thị trang hiện tại\n");
        printf("5. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        getchar(); // xóa ký tự '\n'

        switch (choice) {
            case 1:
                printf("Nhập URL trang mới: ");
                fgets(url, MAX_URL, stdin);
                url[strcspn(url, "\n")] = '\0';  // Xóa newline

                // Đẩy trang hiện tại vào backStack
                push(&backStack, current);

                // Cập nhật trang hiện tại
                strcpy(current, url);

                // Xóa forwardStack
                clearStack(&forwardStack);

                printf(">> Đã chuyển đến: %s\n", current);
                break;

            case 2:
                if (!isEmpty(backStack)) {
                    push(&forwardStack, current);
                    char* backURL = pop(&backStack);
                    strcpy(current, backURL);
                    free(backURL);
                    printf(">> Đã quay lại trang: %s\n", current);
                } else {
                    printf(">> Không thể quay lại.\n");
                }
                break;

            case 3:
                if (!isEmpty(forwardStack)) {
                    push(&backStack, current);
                    char* forwardURL = pop(&forwardStack);
                    strcpy(current, forwardURL);
                    free(forwardURL);
                    printf(">> Đã đi tới trang: %s\n", current);
                } else {
                    printf(">> Không thể đi tới.\n");
                }
                break;

            case 4:
                printf(">> Trang hiện tại: %s\n", current);
                break;

            case 5:
                printf(">> Thoát chương trình...\n");
                break;

            default:
                printf(">> Lựa chọn không hợp lệ.\n");
                break;
        }
    } while (choice != 5);

    // Giải phóng bộ nhớ
    clearStack(&backStack);
    clearStack(&forwardStack);

    return 0;
}
