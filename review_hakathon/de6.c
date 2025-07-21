#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Project {
    int id;
    char title[100];
    char owner[100];
    int priority;
} Project;

// Node cho danh sách liên kết đơn
typedef struct Node {
    Project data;
    struct Node* next;
} Node;

// Node cho danh sách liên kết đôi
typedef struct DNode {
    Project data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

Node* head = NULL;        // Danh sách liên kết đơn – dự án cá nhân
DNode* doneHead = NULL;   // Danh sách liên kết đôi – dự án hoàn thành

Node* createNode(Project p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;
    return newNode;
}

DNode* createDNode(Project p) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = p;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addProject() {
    Project p;
    printf("Nhap ID du an: ");
    scanf("%d", &p.id);
    printf("Nhap ten du an: ");
    getchar(); fgets(p.title, 100, stdin);
    strtok(p.title, "\n");
    printf("Nhap ten nguoi quan ly: ");
    fgets(p.owner, 100, stdin);
    strtok(p.owner, "\n");
    printf("Nhap do uu tien: ");
            scanf("%d", &p.priority);

    Node* newNode = createNode(p);
    newNode->next = head;
    head = newNode;
    printf("Them du an thanh cong!\n");
}

void displayProjects() {
    Node* temp = head;
    printf("===== DANH SACH DU AN =====\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Quan ly: %s | Uu tien: %d\n",
               temp->data.id, temp->data.title, temp->data.owner, temp->data.priority);
        temp = temp->next;
    }
}

void deleteProject() {
    int id;
    printf("Nhap ID du an can xoa: "); scanf("%d", &id);
    Node *temp = head, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Khong tim thay du an!\n");
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Xoa du an thanh cong!\n");
}

void updateProject() {
    int id;
    printf("Nhap ID du an can cap nhat: ");
    scanf("%d", &id);
    Node* temp = head;
    while (temp && temp->data.id != id) temp = temp->next;
    if (!temp) {
        printf("Khong tim thay du an!\n");
        return;
    }
    printf("Cap nhat ten du an: ");
    getchar();
    fgets(temp->data.title, 100, stdin);
    strtok(temp->data.title, "\n");
    printf("Cap nhat nguoi quan ly: "); fgets(temp->data.owner, 100, stdin);
    strtok(temp->data.owner, "\n");
    printf("Cap nhat do uu tien: ");
    scanf("%d", &temp->data.priority);
    printf("Cap nhat thanh cong!\n");
}

void markCompleted() {
    int id;
    printf("Nhap ID du an da hoan thanh: "); scanf("%d", &id);
    Node *temp = head, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay du an!\n");
        return;
    }

    // Chuyển vào danh sách liên kết đôi
    DNode* done = createDNode(temp->data);
    done->next = doneHead;
    if (doneHead) doneHead->prev = done;
    doneHead = done;

    // Xóa khỏi danh sách đơn
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Da danh dau la hoan thanh!\n");
}

void sortProjects() {
    if (!head || !head->next) return;
    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.priority > j->data.priority) {
                Project tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    printf("Da sap xep du an theo do uu tien!\n");
}

void searchProjectByName() {
    char keyword[100];
    printf("Nhap ten du an can tim: "); getchar(); fgets(keyword, 100, stdin); strtok(keyword, "\n");
    Node* temp = head;
    while (temp) {
        if (strstr(temp->data.title, keyword)) {
            printf("ID: %d | Ten: %s | Quan ly: %s | Uu tien: %d\n",
                   temp->data.id, temp->data.title, temp->data.owner, temp->data.priority);
        }
        temp = temp->next;
    }
}


void menuProjectManager() {
    int choice;
    do {
        printf("\n===== PROJECT MANAGER =====\n");
        printf("1. Them moi du an\n2. Hien thi danh sach\n3. Xoa du an\n");
        printf("4. Cap nhat du an\n5. Danh dau hoan thanh\n6. Sap xep theo uu tien\n");
        printf("7. Tim kiem theo ten\n8. Thoat\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProject(); break;
            case 2: displayProjects(); break;
            case 3: deleteProject(); break;
            case 4: updateProject(); break;
            case 5: markCompleted(); break;
            case 6: sortProjects(); break;
            case 7: searchProjectByName(); break;
            case 8: printf("Da thoat Project Manager.\n"); break;
            default: printf("Lua chon sai!\n");
        }
    } while (choice != 8);
}
