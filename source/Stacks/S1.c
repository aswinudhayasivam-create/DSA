#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s->data[s->top];
    s->top--;
    return val;
}


void disStackByCopy(Stack s, const char *name) {
    printf("Stack %s: ", name);
    if (isEmpty(&s)) {
        printf("Stack is empty\n");
        return;
    }
    while (!isEmpty(&s)) {
        int val = pop(&s);
        printf("%d ", val);
    }
    printf("\n");
}

int main() {
    Stack s1, s2;
    int i, m;

    srand(time(0));
    initStack(&s1);
    initStack(&s2);

    printf("Enter number of elements to push in stack: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        int val = rand() % 100;
        if (val % 2 != 0) {
            push(&s1, val);
        } else {
            push(&s2, val);
        }
    }

    disStackByCopy(s1, "S1 (Odd)");
    disStackByCopy(s2, "S2 (Even)");

    return 0;
}