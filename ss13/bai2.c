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
    if (s->top == s->cap - 1) {
        printf("Stack day\n");
        return;
    }
    s->elements[++s->top] = value;
}

void inStack(Stack *s) {
    printf("stack={\n    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->elements[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", s->top, s->cap);
}

int main() {
    Stack *stack = taoStack(5);
    int value;
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(stack, value);
    }
    inStack(stack);
    free(stack->elements);
    free(stack);
    return 0;
}
