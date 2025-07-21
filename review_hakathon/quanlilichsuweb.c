#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL 100

typedef struct Node {
    char url[MAX_URL];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Hàm khởi tạo stack
void init(Stack* s) {
    s->top = NULL;
}

// PUSH
void push(Stack* s, char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = s->top;
    s->top = newNode;
}

// POP
char* pop(Stack* s) {
    if (!s->top) return NULL;
    Node* temp = s->top;
    s->top = s->top->next;
    char* url = strdup(temp->url);
    free(temp);
    return url;
}

// Xóa stack
void clear(Stack* s) {
    while (s->top) {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

// In stack
void printStack(Stack* s) {
    Node* temp = s->top;
    printf(" Lich su truy cap:\n");
    while (temp) {
        printf("- %s\n", temp->url);
        temp = temp->next;
    }
}

int main() {
    Stack backStack, forwardStack;
    init(&backStack);
    init(&forwardStack);

    int choice;
    char url[MAX_URL];

    do {
        printf("\n—— BROWSER HISTORY MANAGER ——\n");
        printf("1. VISIT\n 2. BACK\n 3. FORWARD\n 4. HISTORY\n 5. THOAT\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap URL: ");
                fgets(url, MAX_URL, stdin);
                url[strcspn(url, "\n")] = '\0';
                push(&backStack, url);
                clear(&forwardStack);
                printf(" Da truy cap %s\n", url);
                break;
            case 2: {
                char* last = pop(&backStack);
                if (last) {
                    push(&forwardStack, last);
                    printf(" Da BACK ve: %s\n", backStack.top ? backStack.top->url : "(Trang trong)");
                    free(last);
                } else {
                    printf(" Khong the BACK!\n");
                }
                break;
            }
            case 3: {
                char* next = pop(&forwardStack);
                if (next) {
                    push(&backStack, next);
                    printf("Da FORWARD toi: %s\n", next);
                    free(next);
                } else {
                    printf(" Khong co trang de FORWARD!\n");
                }
                break;
            }
            case 4:
                printStack(&backStack);
                break;
            case 5:
                printf(" Tam biet!\n");
                break;
            default:
                printf(" Lua chon khong hop le.\n");
        }

    } while (choice != 5);

    clear(&backStack);
    clear(&forwardStack);
    return 0;
}
