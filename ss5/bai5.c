#include <stdio.h>
#include <string.h>

void xoaKhoangTrang(char str[]) {
    int i, j = 0;
    char temp[100];
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str,temp);
}
int laDoiXung(char str[], int dau, int cuoi) {
    if (dau >= cuoi) return 1;
    if (str[dau] != str[cuoi]) return 0;
    return laDoiXung(str, dau + 1, cuoi - 1);
}
int main() {
    char chuoi[100];
    printf("nhap chuoi");
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strlen(chuoi) - 1] = '\0';
    xoaKhoangTrang(chuoi);

    if (laDoiXung(chuoi,0,strlen(chuoi) - 1)) {
        printf("Palindrome valid\n");

    }else {
        printf("Palindrome invalid\n");
    }
    return 0;

}