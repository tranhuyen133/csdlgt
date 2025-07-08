#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int *data;
    int top;
    int cap;
} Stack;

Stack* taoStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(cap * sizeof(int));
    s->top = -1;
    s->cap = cap;
    return s;
}

void push(Stack *s, int x) {
    if (s->top < s->cap - 1) {
        s->data[++s->top] = x;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return 0;
    return s->data[s->top--];
}

int tinhPostfix(char *expr) {
    int n = strlen(expr);
    Stack *s = taoStack(n);
    for (int i = 0; i < n; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(s, c - '0');
        } else {
            int b = pop(s);
            int a = pop(s);
            int kq = 0;
            if (c == '+') kq = a + b;
            else if (c == '-') kq = a - b;
            else if (c == '*') kq = a * b;
            else if (c == '/') kq = a / b;
            push(s, kq);
        }
    }
    int result = pop(s);
    free(s->data);
    free(s);
    return result;
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int kq = tinhPostfix(expr);
    printf("%d\n", kq);
    return 0;
}
