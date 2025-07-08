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

int pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return s->elements[s->top--];
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
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    inStack(stack);
    int value = pop(stack);
    if (value != -1) printf("%d\n", value);
    inStack(stack);
    Stack *empty = taoStack(5);
    pop(empty);
    free(stack->elements);
    free(stack);
    free(empty->elements);
    free(empty);
    return 0;
}
