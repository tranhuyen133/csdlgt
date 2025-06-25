#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int main() {
    Student students[SIZE];

    for (int i = 0; i < SIZE; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Ten: ");
        scanf("%s", students[i].name);

        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }

    int searchId;
    printf("Nhap ID can tim: ");
    scanf("%d", &searchId);

    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (students[i].id == searchId) {
            printf("{ id: %d, name: \"%s\", age: %d }\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien khong ton tai\n");
    }

    return 0;
}
