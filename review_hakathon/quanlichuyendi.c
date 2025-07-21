#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Trip
typedef struct Trip {
    int id;
    char destination[100];
    char startDate[20];
    int duration;
} Trip;

// Node cho danh sách liên kết đơn (chuyến đi sắp tới)
typedef struct TripNode {
    Trip data;
    struct TripNode* next;
} TripNode;

// Node cho danh sách liên kết đôi (chuyến đi đã hoàn thành)
typedef struct CompletedTripNode {
    Trip data;
    struct CompletedTripNode* prev;
    struct CompletedTripNode* next;
} CompletedTripNode;

// Danh sách chuyến đi sắp tới
TripNode* upcomingHead = NULL;
// Danh sách chuyến đi đã hoàn thành
CompletedTripNode* completedHead = NULL;

// Hàm tạo chuyến đi
Trip createTrip() {
    Trip t;
    printf("Nhap ID: ");
    scanf("%d", &t.id);
    getchar();
    printf("Nhap diem den: ");
    fgets(t.destination, 100, stdin);
    t.destination[strcspn(t.destination, "\n")] = '\0';
    printf("Nhap ngay khoi hanh (dd/mm/yyyy): ");
    fgets(t.startDate, 20, stdin);
    t.startDate[strcspn(t.startDate, "\n")] = '\0';
    printf("Nhap thoi luong (ngay): ");
    scanf("%d", &t.duration);
    return t;
}

// 1. Thêm chuyến đi
void addTrip() {
    TripNode* newNode = (TripNode*)malloc(sizeof(TripNode));
    newNode->data = createTrip();
    newNode->next = NULL;

    if (upcomingHead == NULL) {
        upcomingHead = newNode;
    } else {
        TripNode* temp = upcomingHead;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf(" Da them chuyen di!\n");
}

// 2. Hiển thị danh sách
void displayTrips() {
    TripNode* temp = upcomingHead;
    if (!temp) {
        printf(" Danh sach rong.\n");
        return;
    }
    printf(" Danh sach chuyen di sap toi:\n");
    while (temp) {
        printf("- ID: %d, Diem den: %s, Ngay: %s, %d ngay\n",
            temp->data.id, temp->data.destination, temp->data.startDate, temp->data.duration);
        temp = temp->next;
    }
}

// 3. Xóa chuyến đi theo ID
void deleteTrip() {
    int id;
    printf("Nhap ID chuyen di can xoa: ");
    scanf("%d", &id);

    TripNode *temp = upcomingHead, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf(" Khong tim thay ID.\n");
        return;
    }

    if (!prev) {
        upcomingHead = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("🗑 Da xoa chuyen di!\n");
}

// 4. Cập nhật chuyến đi
void updateTrip() {
    int id;
    printf("Nhap ID can cap nhat: ");
    scanf("%d", &id);
    getchar();

    TripNode* temp = upcomingHead;
    while (temp && temp->data.id != id)
        temp = temp->next;

    if (!temp) {
        printf(" Khong tim thay chuyen di.\n");
        return;
    }

    printf("Cap nhat diem den: ");
    fgets(temp->data.destination, 100, stdin);
    temp->data.destination[strcspn(temp->data.destination, "\n")] = '\0';

    printf("Cap nhat ngay khoi hanh: ");
    fgets(temp->data.startDate, 20, stdin);
    temp->data.startDate[strcspn(temp->data.startDate, "\n")] = '\0';

    printf("Cap nhat thoi luong: ");
    scanf("%d", &temp->data.duration);
    printf(" Da cap nhat!\n");
}

// 5. Đánh dấu hoàn thành (chuyển sang DLL)
void markTripCompleted() {
    int id;
    printf("Nhap ID da hoan thanh: ");
    scanf("%d", &id);

    TripNode *temp = upcomingHead, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf(" Khong tim thay!\n");
        return;
    }

    if (prev == NULL)
        upcomingHead = temp->next;
    else
        prev->next = temp->next;

    CompletedTripNode* newNode = (CompletedTripNode*)malloc(sizeof(CompletedTripNode));
    newNode->data = temp->data;
    newNode->next = completedHead;
    newNode->prev = NULL;
    if (completedHead)
        completedHead->prev = newNode;
    completedHead = newNode;

    free(temp);
    printf("Da danh dau hoan thanh!\n");
}

// So sánh ngày (tăng dần)
int compareDate(char* d1, char* d2) {
    int dd1, mm1, yy1, dd2, mm2, yy2;
    sscanf(d1, "%d/%d/%d", &dd1, &mm1, &yy1);
    sscanf(d2, "%d/%d/%d", &dd2, &mm2, &yy2);
    if (yy1 != yy2) return yy1 - yy2;
    if (mm1 != mm2) return mm1 - mm2;
    return dd1 - dd2;
}

// 6. Sắp xếp theo ngày khởi hành
void sortTrips() {
    if (!upcomingHead || !upcomingHead->next) return;

    TripNode *i, *j;
    for (i = upcomingHead; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (compareDate(i->data.startDate, j->data.startDate) > 0) {
                Trip temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Da sap xep!\n");
}

// 7. Tìm kiếm theo điểm đến
void searchTrip() {
    char dest[100];
    getchar();
    printf("Nhap diem den can tim: ");
    fgets(dest, 100, stdin);
    dest[strcspn(dest, "\n")] = '\0';

    TripNode* temp = upcomingHead;
    int found = 0;
    while (temp) {
        if (strcmp(temp->data.destination, dest) == 0) {
            printf("- ID: %d, Ngay: %s, %d ngay\n",
                temp->data.id, temp->data.startDate, temp->data.duration);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf(" Khong tim thay chuyen di.\n");
}

// 8. Menu chính
int main() {
    int choice;
    do {
        printf("\n———— TRIP MANAGER ————\n");
        printf("1. Them chuyen di\n2. Hien thi danh sach\n3. Xoa chuyen di\n4. Cap nhat\n");
        printf("5. Danh dau hoan thanh\n6. Sap xep theo ngay\n7. Tim kiem diem den\n8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTrip(); break;
            case 2: displayTrips(); break;
            case 3: deleteTrip(); break;
            case 4: updateTrip(); break;
            case 5: markTripCompleted(); break;
            case 6: sortTrips(); break;
            case 7: searchTrip(); break;
            case 8: printf("👋Thoat!\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    return 0;
}
