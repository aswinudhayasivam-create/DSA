#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left, *right;
} BT;

BT *makeNode(int data)
{
    BT *t = (BT *)malloc(sizeof(BT));

    t->data = data;
    t->left = t->right = NULL;

    return t;
}

void inOrder(BT *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%5d", t->data);
        inOrder(t->right);
    }
}

BT *insert(BT *t, int data)
{
    if (!t)
        return makeNode(data);

    if (t->data > data)
        t->left = insert(t->left, data);

    if (t->data < data)
        t->right = insert(t->right, data);

    return t;
}

int search(BT *t, int data)
{
    if (!t)
        return 0;

    if (t->data == data)
        return 1;

    if (t->data > data)
        return search(t->left, data);

    return search(t->right, data);
}

int count(BT *t)
{
    if (!t)
        return 0;

    return 1 + count(t->left) + count(t->right);
}

int height(BT *t)
{
    if (!t)
        return 0;

    int l = height(t->left);
    int r = height(t->right);

    return l > r ? l + 1 : r + 1;
}

int main()
{
    BT *t = NULL;

    for(int i = 0; i < 10; i++)
        t = insert(t, rand() % 100);

    inOrder(t);

    printf("%5d", count(t));

    return 0;
}