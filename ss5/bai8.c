#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringToInt(char str[], int index, int len, int *result) {
    if (index == len) return 1;

    if (!isdigit(str[index])) return 0;

    *result = (*result) * 10 + (str[index] - '0');
    return stringToInt(str, index + 1, len, result);
}

int main() {
    char str[100];
    int result = 0;

    printf("Nhap chuoi so: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int isNegative = 0;
    int startIndex = 0;

    if (str[0] == '-') {
        isNegative = 1;
        startIndex = 1;
    }

    if (strlen(str) == 0 || (isNegative && strlen(str) == 1)) {
        printf("Input khong hop le\n");
        return 1;
    }

    if (stringToInt(str, startIndex, strlen(str), &result)) {
        if (isNegative) result = -result;
        printf("So nguyen = %d\n", result);
    } else {
        printf("Input khong hop le\n");
    }

    return 0;
}
