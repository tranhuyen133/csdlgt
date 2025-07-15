#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Product {
    int id;
    char name[100];
    float price;
    int quantity;
    struct Product *next; // cho danh sách liên kết đơn
    struct Product *prev; // cho danh sách liên kết đôi
} Product;

Product *head = NULL;       // Danh sách đơn: sản phẩm đang bán
Product *soldHead = NULL;   // Danh sách đôi: đầu danh sách đã bán
Product *soldTail = NULL;   // Đuôi danh sách đã bán

char *toLower(char *str) {
    static char lower[100];
    int i;
    for (i = 0; str[i]; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[i] = '\0';
    return lower;
}

int isDuplicateName(char *name) {
    Product *p = head;
    while (p) {
        if (strcmp(toLower(p->name), toLower(name)) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}

void addProduct() {
    Product *p = (Product *)malloc(sizeof(Product));
    printf("Nhap ID: ");
    scanf("%d", &p->id);
    printf("Nhap ten: ");
    getchar();
    fgets(p->name, 100, stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    if (isDuplicateName(p->name)) {
        printf("Ten san pham bi trung!\n");
        free(p);
        return;
    }

    printf("Nhap gia: ");
    scanf("%f", &p->price);
    printf("Nhap so luong: ");
    scanf("%d", &p->quantity);

    p->next = head;
    head = p;
    p->prev = NULL;

    printf("\nThem thanh cong!\n");
}

void displayProducts() {
    Product *p = head;
    if (!p) {
        printf("Khong co san pham.\n");
        return;
    }

    printf("\n=== Danh sach san pham ===\n");
    while (p) {
        printf("ID: %d | Ten: %s | Gia: %.2f | So luong: %d\n",
               p->id, p->name, p->price, p->quantity);
        p = p->next;
    }
}

void deleteProduct() {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);

    Product *cur = head, *prev = NULL;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    if (!prev)
        head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
    printf("Xoa thanh cong!\n");
}

void updateProduct() {
    int id;
    char name[100];
    printf("Nhap ID can cap nhat: ");
    scanf("%d", &id);

    Product *p = head;
    while (p && p->id != id)
        p = p->next;

    if (!p) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    printf("Nhap ten moi: ");
    getchar();
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strcmp(toLower(p->name), toLower(name)) != 0 && isDuplicateName(name)) {
        printf("Ten bi trung!\n");
        return;
    }

    strcpy(p->name, name);
    printf("Nhap gia moi: ");
    scanf("%f", &p->price);
    printf("Nhap so luong moi: ");
    scanf("%d", &p->quantity);

    printf("Cap nhat thanh cong!\n");
}

void markAsSold() {
    int id;
    printf("Nhap ID da ban: ");
    scanf("%d", &id);

    Product *cur = head, *prev = NULL;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur) {
        printf("Khong tim thay san pham.\n");
        return;
    }

    if (!prev)
        head = cur->next;
    else
        prev->next = cur->next;

    cur->next = NULL;
    cur->prev = soldTail;

    if (soldTail)
        soldTail->next = cur;
    else
        soldHead = cur;

    soldTail = cur;

    printf("Da chuyen vao danh sach da ban.\n");
}

void displaySold() {
    Product *p = soldHead;
    if (!p) {
        printf("Chua co san pham da ban.\n");
        return;
    }

    printf("\n=== San pham da ban ===\n");
    while (p) {
        printf("ID: %d | Ten: %s | Gia: %.2f\n",
               p->id, p->name, p->price);
        p = p->next;
    }
}

void bubbleSort() {
    if (!head || !head->next)
        return;

    int swapped;
    do {
        swapped = 0;
        Product *p = head, *prev = NULL, *next;
        while (p && p->next) {
            next = p->next;
            if (p->price > next->price) {
                if (!prev)
                    head = next;
                else
                    prev->next = next;

                p->next = next->next;
                next->next = p;
                swapped = 1;
                prev = next;
            } else {
                prev = p;
                p = p->next;
            }
        }
    } while (swapped);

    printf("\nDa sap xep xong.\n");
}

void searchProduct() {
    char name[100];
    printf("Nhap ten can tim: ");
    getchar();
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    Product *p = head;
    int found = 0;
    while (p) {
        if (strcmp(toLower(p->name), toLower(name)) == 0) {
            printf("Tim thay: ID: %d | Gia: %.2f | SL: %d\n",
                   p->id, p->price, p->quantity);
            found = 1;
            break;
        }
        p = p->next;
    }

    if (!found)
        printf("Khong tim thay.\n");
}


int main() {
    int choice;
    do {
        printf("\n———— PRODUCT MANAGER ————\n");
        printf("1. Them san pham\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Xoa theo ID\n");
        printf("4. Cap nhat thong tin\n");
        printf("5. Danh dau da ban\n");
        printf("6. Hien thi da ban\n");
        printf("7. Sap xep theo gia\n");
        printf("8. Tim kiem theo ten\n");
        printf("9. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                markAsSold();
                break;
            case 6:
                displaySold();
                break;
            case 7:
                bubbleSort();
                break;
            case 8:
                searchProduct();
                break;
            case 9:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}
