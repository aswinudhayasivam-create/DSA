#include <stdio.h>
#define MAX_SIZE 5

typedef enum {FALSE, TRUE} Bool;

typedef struct {
    int val[MAX_SIZE];
    int top;
} Stack;

Stack createStack();
Bool isEmpty(Stack s);
Bool isFull(Stack s);
Bool push(Stack *s, int val);
Bool pop(Stack *s, int *val);
int peek(Stack s);

int main() {
    Stack s1;
    s1 = createStack();

    int poppedVal;
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    printf("Top element: %d\n", peek(s1));

    if (pop(&s1, &poppedVal) == TRUE) {
        printf("Popped element: %d\n", poppedVal);
    }

    printf("Top element after pop: %d\n", peek(s1));

    return 0;
}

Stack createStack() {
    Stack s;
    s.top = -1;
    return s;
}

Bool isEmpty(Stack s) {
    return s.top == -1;
}

Bool isFull(Stack s) {
    return s.top == MAX_SIZE - 1;
}

Bool push(Stack *s, int val) {
    if (isFull(*s)) {
        return FALSE;
    }
    s->top = s->top + 1;
    s->val[s->top] = val;
    return TRUE;
}

Bool pop(Stack *s, int *val) {
    if (isEmpty(*s)) {
        return FALSE;
    }
    *val = s->val[s->top];
    s->top = s->top - 1;
    return TRUE;
}

int peek(Stack s) {
    if (isEmpty(s)) {
        return -9999;
    }
    return s.val[s.top];
}
