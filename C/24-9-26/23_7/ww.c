#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct
{
    int rear;
    int fro;
    char arr[MAX];
} Q;
void init(Q *q)
{
    q->rear = q->fro = 0;
}
int isEmpty(Q q)
{
    return q.fro == q.rear;
}
int isFull(Q q)
{
    return (q.rear + 1) % MAX == q.fro;
}
int enqueue(Q *q, char val)
{

    if (isFull(*q))
        return 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
    return 1;
}
int dequeue(Q *q, char *val)
{
    if (isEmpty(*q))
        return 0;
    q->fro = (q->fro + 1) % MAX;
    *val = q->arr[q->fro];
    return 1;
}
int main()
{
    Q q;
    int i;
    char x;
    char s[MAX];
    init(&q);
    printf("Enter the string in the form of w.w: ");
    scanf("%s", s);
    for (i = 0; s[i] != '.' && s[i] != '\0'; i++)
    {
        enqueue(&q, s[i]);
    }
    while (dequeue(&q, &x))
    {
        if (s[++i] != x)
        {
            printf("Not Balanced\n");
            return 0;
        }
    }
    if (s[i + 1] != '\0')
        printf("Not Balanced\n");
    else
        printf("Well Balanced\n");
    return 0;
}

