#include<malloc.h>
#include<stdio.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} NODE;

NODE *makeNODE(int data)
{
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void display(NODE *l)
{
    while (l)
    {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

/* Insert at the front — O(1) */
NODE *inserthead(NODE *l, int data)
{
    NODE *temp = makeNODE(data);
    temp->next = l;
    return temp;
}

/* Insert at the end — O(n), must walk to the last node */
NODE *inserttail(NODE *l, int data)
{
    NODE *temp = makeNODE(data);
    if (l == NULL)
        return temp;

    NODE *cur = l;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    return l;
}

/* Search for a value — returns 1 if found, 0 otherwise */
int search(NODE *l, int key)
{
    while (l)
    {
        if (l->data == key)
            return 1;
        l = l->next;
    }
    return 0;
}

/* Count nodes */
int count(NODE *l)
{
    int c = 0;
    while (l)
    {
        c++;
        l = l->next;
    }
    return c;
}

/* Delete the first node matching a value */
NODE *deleteValue(NODE *l, int key)
{
    if (l == NULL)
        return NULL;

    if (l->data == key)
    {
        NODE *temp = l->next;
        free(l);
        return temp;
    }

    NODE *cur = l;
    while (cur->next != NULL && cur->next->data != key)
        cur = cur->next;

    if (cur->next != NULL)
    {
        NODE *toDelete = cur->next;
        cur->next = toDelete->next;
        free(toDelete);
    }
    return l;
}

/* Reverse the list in place */
NODE *reverse(NODE *l)
{
    NODE *prev = NULL, *cur = l, *next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main()
{
    NODE *l1 = makeNODE(200);
    l1->next = makeNODE(500);
    l1 = inserthead(l1, 1000);
    l1 = inserttail(l1, 300);

    printf("List 1: ");
    display(l1);

    printf("Count: %d\n", count(l1));
    printf("Search 500: %s\n", search(l1, 500) ? "Found" : "Not found");
    printf("Search 999: %s\n", search(l1, 999) ? "Found" : "Not found");

    l1 = deleteValue(l1, 500);
    printf("After deleting 500: ");
    display(l1);

    l1 = reverse(l1);
    printf("After reversing: ");
    display(l1);

    return 0;
}
