#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return 1; // Tìm thấy
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0; // Không tìm thấy
}

int main() {
    int n, x;
    int *arr;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le!\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    if (binarySearch(arr, n, x)) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    free(arr);
    return 0;
}
