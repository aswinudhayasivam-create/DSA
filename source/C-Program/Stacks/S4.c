#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char ch) {
    if (s->top < MAX - 1)
        s->data[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (s->top == -1)
        return '\0';
    return s->data[(s->top)--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.top == -1)
                return 0;

            char open = pop(&s);
            if (!isMatching(open, ch))
                return 0;
        }
    }

    return s.top == -1;
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (isBalanced(expr))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}