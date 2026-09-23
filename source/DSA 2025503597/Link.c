#include <stdio.h>
#include <malloc.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} NODE;

void display(NODE *l)
{
    while (l)
    {
        printf("%p - %5d\n", (void *)l, l->data);
        l = l->next;
    }
}

NODE *makeNODE(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

NODE *inserthead(NODE *l, int data)
{
    NODE *temp = makeNODE(data);
    temp->next = l;

    return temp;
}

int main()
{
    NODE *l1 = makeNODE(200);
    NODE *l2 = makeNODE(100);

    l1->next = makeNODE(500);

    l1 = inserthead(l1, 1000);

    NODE *l3 = makeNODE(300);

    printf("List 1:\n");
    display(l1);

    printf("\nList 2:\n");
    display(l2);

    printf("\nList 3:\n");
    display(l3);

    return 0;
}
