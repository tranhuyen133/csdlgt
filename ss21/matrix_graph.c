#include <stdio.h>
//tao ma tran 2 chieu
int MATRIX[3][3];
//Ham khoi tao ma tran 2 chieu voi cac gia tri o la 0
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
//khoi tao ham tao lien ket
void adjacency(int U,int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;//DO THI VO HUONG THI PHAI QUAN HE 2 CHIEU
}
//TAO HAM HIEN THI MA TRAN
void printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

