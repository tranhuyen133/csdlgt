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
    if (s->top == s->cap - 1) return;
    s->elements[++s->top] = value;
}

void duyetStack(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->elements[i]);
    }
}

int main() {
    Stack *stack = taoStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    duyetStack(stack);
    free(stack->elements);
    free(stack);
    return 0;
}
