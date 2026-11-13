#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct STACK {
    char *val;
    int top;
    int n;
} STACK;

STACK createStack(int length) {
    STACK s;
    s.top = 0;
    s.val = (char *)malloc(length * sizeof(char));
    s.n = length;
    return s;
}

bool isFull(STACK *s) {
    if(s->top == s->n) return 1;
    return 0;
}

bool isEmpty(STACK *s) {
    if(s->top == 0) return 1;
    return 0;
}

bool push(STACK *s, char x) {
    if(isFull(s)) return 0;
    s->val[s->top] = x;
    s->top++;
    return 1;
}

bool pop(STACK *s, char *x) {
    if(isEmpty(s)) return 0;
    *x = s->val[s->top - 1];
    s->top--;
    return 1;
}

char peek(STACK s) {
    return s.val[s.top - 1];
}

int main() {
    char str[100];
    char x;

    printf("Enter a string : \n");
    scanf("%s", str);

    int len = strlen(str);
    STACK s1 = createStack(len);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            push(&s1, str[i]);
        }
        else {
            if (!pop(&s1, &x)) {
                printf("Not Well Balanced \n");
                free(s1.val);
                return 0;
            }
            if(str[i] != x + 32) {
                printf("Not Well Balanced \n");
                free(s1.val);
                return 0;
            }
        }
    }

    if (!isEmpty(&s1)) {
        printf("Not Well Balanced\n");
    } else {
        printf("Well Balanced\n");
    }

    free(s1.val);
    return 0;
}
