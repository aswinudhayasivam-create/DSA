#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Q
{
    int rear,fr,n;
    char *arr;
} Q;

void create_queue(Q *q,int len)
{
    q->arr=(char *)malloc(len * sizeof(char));
    q->n=len;
    q->rear=0;
    q->fr=0;
}

bool isEmpty(Q *q)
{
    if(q->rear==q->fr)
        return 1;
    return 0;
}
bool isFull(Q *q)
{
    if((q->rear+1)%q->n==q->fr) return 1;
    return 0;
}
bool enqueue(Q *q,char val)
{
    if(isFull(q)) return 0;
    q->rear=(q->rear+1)%q->n;
    q->arr[q->rear]=val;
   return 1;
}
bool dequeue(Q *q,char *val)
{
    if(isEmpty(q)) return 0;
    q->fr=(q->fr+1)%q->n;
    *val=q->arr[q->fr];
    return 1;
}
int main()
{
    Q q1,q2;int i;
    char x;
    char s[100];
    printf("Enter string in form w.w.w:");
    scanf("%s", s);
    int n=strlen(s);
    create_queue(&q1,n+1);
    create_queue(&q2,n+1);
    for(i=0;s[i]!='.';i++)
    {
        enqueue(&q1,s[i]);
    }
    i++;
    while(dequeue(&q1,&x))
    {
        if(s[i]!=x)
        {
            printf("Not well balanced");
            free(q1.arr);
            free(q2.arr);
            return 0;
        }
        enqueue(&q2,x);
        i++;
    }
    i++;
    while(s[i]!='\0')
    {
        if (!dequeue(&q2,&x))
        {
            printf("Not well balanced");
            free(q1.arr);
            free(q2.arr);
            return 0;
        }
        if(s[i]!=x)
        {
            printf("Not well balanced");
            free(q1.arr);
            free(q2.arr);
            return 0;
        }
        i++;
    }
    if(dequeue(&q1,&x)|| dequeue(&q2,&x))
    {
        printf("Not well balanced");
        free(q1.arr);
        free(q2.arr);
        return 0;
    }
    printf("Well balanced");
    free(q1.arr);
    free(q2.arr);
    return 0;
}
