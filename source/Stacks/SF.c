#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize Stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if Stack is Full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if Stack is Empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push Element
void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    s->data[++(s->top)] = val;
    printf("Pushed: %d\n", val);
}

// Pop Element
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Peek Top Element
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s->data[s->top];
}

// Display Stack Contents
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top Element (Peek): %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    display(&s);

    return 0;
}