#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return stack->top->data;
}

void printStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack* stack = createStack();
    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printStack(stack);

    int topValue = peek(stack);
    if (topValue != -1) {
        printf("%d\n", topValue);
    }

    Stack* emptyStack = createStack();
    peek(emptyStack);

    return 0;
}
