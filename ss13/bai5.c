#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int top;
    int cap;
} Stack;

Stack* taoStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->elements = (int*)malloc(cap * sizeof(int));
    s->top = -1;
    s->cap = cap;
    return s;
}

void push(Stack *s, int value) {
    if (s->top < s->cap - 1) {
        s->elements[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->elements[s->top--];
}

void daoNguocMang(int arr[], int n) {
    Stack *s = taoStack(n);
    for (int i = 0; i < n; i++) {
        push(s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(s);
    }
    free(s->elements);
    free(s);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 1000) return 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    daoNguocMang(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
