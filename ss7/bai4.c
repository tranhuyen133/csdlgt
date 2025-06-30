#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sapXepChuoi(char str[]) {
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("Chuoi khong hop le\n");
        return 1;
    }

    printf("Truoc khi sap xep: %s\n", str);

    sapXepChuoi(str);

    printf("Sau khi sap xep: %s\n", str);

    return 0;
}
