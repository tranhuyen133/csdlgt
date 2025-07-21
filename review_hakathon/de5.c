#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    char category[50];
    float price;
} Book;

// Node danh sách liên kết đơn
typedef struct SNode {
    Book data;
    struct SNode* next;
} SNode;

// Node danh sách liên kết đôi
typedef struct DNode {
    Book data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

SNode* bookList = NULL;       // sách chưa đọc
DNode* readList = NULL;       // sách đã đọc

SNode* createSNode(Book b) {
    SNode* node = (SNode*)malloc(sizeof(SNode));
    node->data = b;
    node->next = NULL;
    return node;
}

DNode* createDNode(Book b) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = b;
    node->next = NULL;
    node->prev = NULL;
    return node;
}



void addBook() {
    Book b;
    printf("Nhap ID sach: "); scanf("%d", &b.id);
    getchar();
    printf("Nhap ten sach: "); fgets(b.title, 100, stdin); strtok(b.title, "\n");
    printf("Nhap tac gia: "); fgets(b.author, 100, stdin); strtok(b.author, "\n");
    printf("Nhap the loai: "); fgets(b.category, 50, stdin); strtok(b.category, "\n");
    printf("Nhap gia sach: "); scanf("%f", &b.price);

    SNode* node = createSNode(b);
    node->next = bookList;
    bookList = node;
    printf("Them sach thanh cong!\n");
}

void displayBooks() {
    SNode* temp = bookList;
    printf("=== DANH SACH SACH CHUA DOC ===\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Tac gia: %s | The loai: %s | Gia: %.2f\n",
               temp->data.id, temp->data.title, temp->data.author,
               temp->data.category, temp->data.price);
        temp = temp->next;
    }
}

void deleteBook() {
    int id;
    printf("Nhap ID sach can xoa: "); scanf("%d", &id);
    SNode *temp = bookList, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay sach!\n");
        return;
    }
    if (!prev) bookList = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Xoa sach thanh cong!\n");
}

void updateBook() {
    int id;
    printf("Nhap ID sach can cap nhat: "); scanf("%d", &id);
    SNode* temp = bookList;
    while (temp && temp->data.id != id) temp = temp->next;
    if (!temp) {
        printf("Khong tim thay sach!\n");
        return;
    }
    getchar();
    printf("Cap nhat ten sach: "); fgets(temp->data.title, 100, stdin); strtok(temp->data.title, "\n");
    printf("Cap nhat tac gia: "); fgets(temp->data.author, 100, stdin); strtok(temp->data.author, "\n");
    printf("Cap nhat the loai: "); fgets(temp->data.category, 50, stdin); strtok(temp->data.category, "\n");
    printf("Cap nhat gia: "); scanf("%f", &temp->data.price);
    printf("Cap nhat thanh cong!\n");
}

void markAsRead() {
    int id;
    printf("Nhap ID sach da doc xong: "); scanf("%d", &id);
    SNode *temp = bookList, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay sach!\n");
        return;
    }

    DNode* node = createDNode(temp->data);
    node->next = readList;
    if (readList) readList->prev = node;
    readList = node;

    if (!prev) bookList = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Sach da chuyen vao danh sach da doc.\n");
}

void sortBooksByPrice() {
    if (!bookList || !bookList->next) return;
    SNode *i, *j;
    for (i = bookList; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.price > j->data.price) {
                Book tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    printf("Da sap xep sach theo gia tang dan.\n");
}

void searchBookByTitle() {
    char keyword[100];
    getchar();
    printf("Nhap tieu de can tim: "); fgets(keyword, 100, stdin); strtok(keyword, "\n");
    SNode* temp = bookList;
    while (temp) {
        if (strstr(temp->data.title, keyword)) {
            printf("ID: %d | Ten: %s | Tac gia: %s | The loai: %s | Gia: %.2f\n",
                   temp->data.id, temp->data.title, temp->data.author,
                   temp->data.category, temp->data.price);
        }
        temp = temp->next;
    }
}

void menuBookManager() {
    int choice;
    do {
        printf("\n=== BOOK MANAGER ===\n");
        printf("1. Them sach\n2. Hien thi danh sach\n3. Xoa sach\n4. Cap nhat thong tin\n");
        printf("5. Danh dau da doc\n6. Sap xep theo gia\n7. Tim theo tieu de\n8. Thoat\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: deleteBook(); break;
            case 4: updateBook(); break;
            case 5: markAsRead(); break;
            case 6: sortBooksByPrice(); break;
            case 7: searchBookByTitle(); break;
            case 8: printf("Da thoat Book Manager.\n"); break;
            default: printf("Lua chon sai!\n");
        }
    } while (choice != 8);
}
