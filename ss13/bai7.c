#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int cap;
} Stack;

Stack* taoStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (char*)malloc(cap * sizeof(char));
    s->top = -1;
    s->cap = cap;
    return s;
}

void push(Stack *s, char c) {
    if (s->top < s->cap - 1) {
        s->data[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top--];
}

char peek(Stack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top];
}

bool kiemTraHopLe(char *str) {
    Stack *s = taoStack(strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char top = peek(s);
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                pop(s);
                } else {
                    free(s->data);
                    free(s);
                    return false;
                }
        }
    }
    bool hopLe = (s->top == -1);
    free(s->data);
    free(s);
    return hopLe;
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    if (kiemTraHopLe(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
