#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *elements;
    int top;
    int cap;
} Stack;

Stack* taoStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->elements = (char*)malloc(cap * sizeof(char));
    s->top = -1;
    s->cap = cap;
    return s;
}

void push(Stack *s, char c) {
    if (s->top < s->cap - 1) {
        s->elements[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->elements[s->top--];
}

bool laDoiXung(char str[]) {
    int n = strlen(str);
    Stack *s = taoStack(n);
    for (int i = 0; i < n; i++) {
        push(s, str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (str[i] != pop(s)) {
            free(s->elements);
            free(s);
            return false;
        }
    }
    free(s->elements);
    free(s);
    return true;
}

int main() {
    char chuoi[1000];
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strcspn(chuoi, "\n")] = '\0';
    if (laDoiXung(chuoi)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
