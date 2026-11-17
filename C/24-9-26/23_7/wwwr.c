

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct

{

    char *val;

    int top;

    int n;

} STACK;

STACK createStack(int length)

{

    STACK s;

    s.top = 0;

    s.n = length;

    s.val = (char *)malloc(length * sizeof(char));

    return s;

}

int isStackFull(STACK *s)

{

    return s->top == s->n;

}

int isStackEmpty(STACK *s)

{

    return s->top == 0;

}

int push(STACK *s, char x)

{

    if (isStackFull(s))

        return 0;

    s->val[s->top] = x;

    s->top++;

    return 1;

}

int pop(STACK *s, char *x)

{

    if (isStackEmpty(s))

        return 0;

    *x = s->val[s->top - 1];

    s->top--;

    return 1;

}

typedef struct

{

    int rear;

    int fr;

    int n;

    char *arr;

} Q;

void createQueue(Q *q, int len)

{

    q->arr = (char *)malloc(len * sizeof(char));

    q->n = len;

    q->rear = 0;

    q->fr = 0;

}

int isQueueEmpty(Q *q)

{

    return q->rear == q->fr;

}

int isQueueFull(Q *q)

{

    return ((q->rear + 1) % q->n) == q->fr;

}

int enqueue(Q *q, char val)

{

    if (isQueueFull(q))

        return 0;

    q->rear = (q->rear + 1) % q->n;

    q->arr[q->rear] = val;

    return 1;

}

int dequeue(Q *q, char *val)

{

    if (isQueueEmpty(q))

        return 0;

    q->fr = (q->fr + 1) % q->n;

    *val = q->arr[q->fr];

    return 1;

}

int main()

{

    char str[100], x;

    int i;

    STACK s1;

    Q q;

    printf("Enter string of form w.w.rev(w): ");

    scanf("%s", str);

    createQueue(&q, strlen(str) + 1);

    s1 = createStack(strlen(str));

    for (i = 0; str[i] != '.'; i++)

    {

        push(&s1, str[i]);

        enqueue(&q, str[i]);

    }

    while (str[++i] != '.')

    {

        dequeue(&q, &x);

        if (str[i] != x)

        {

            printf("Incorrect form\n");

            free(s1.val);

            free(q.arr);

            return 0;

        }

    }

    for (i = i + 1; str[i] != '\0'; i++)

    {

        pop(&s1, &x);

        if (str[i] != x)

        {

            printf("Incorrect form\n");

            free(s1.val);

            free(q.arr);

            return 0;

        }

    }

    if (pop(&s1, &x) || dequeue(&q, &x))

    {

        printf("Incorrect form\n");

    }

    else

    {

        printf("Correct form\n");

    }

    free(s1.val);

    free(q.arr);

    return 0;

}


