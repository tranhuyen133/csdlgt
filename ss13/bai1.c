#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

Stack* khoiTaoStack(int maxSize) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(maxSize * sizeof(int));
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack day\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void inStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack *stack = khoiTaoStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    inStack(stack);
    pop(stack);
    inStack(stack);
    free(stack->arr);
    free(stack);
    return 0;
}
