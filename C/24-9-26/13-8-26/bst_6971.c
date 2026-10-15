#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

BT *insert(BT *t, int data, int *inserted)
{
    if (!t) {
        *inserted = 1;          /* new node actually created */
        return makeNode(data);
    }
    if (t->data > data)
        t->left = insert(t->left, data, inserted);
    else if (t->data < data)
        t->right = insert(t->right, data, inserted);
    /* if equal, do nothing -> duplicate, *inserted stays 0 */
    return t;
}

int search(BT *t, int data)
{
    if (!t) return 0;
    if (t->data == data) return 1;
    if (t->data > data) return search(t->left, data);
    return search(t->right, data);
}

int count(BT *t)
{
    if (!t) return 0;
    return 1 + count(t->left) + count(t->right);
}

int height(BT *t)
{
    if (!t) return 0;
    int l = height(t->left);
    int r = height(t->right);
    return l > r ? l + 1 : r + 1;
}

void freeTree(BT *t)
{
    if (t) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

int main()
{
    srand(time(NULL));   /* seed so we get different numbers each run */

    BT *t = NULL;
    int duplicates = 0;

    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        int inserted = 0;
        t = insert(t, val, &inserted);
        if (!inserted) duplicates++;
    }

    printf("In-order (sorted) values:\n");
    inOrder(t);
    printf("\n\n");

    printf("Node count : %d\n", count(t));
    printf("Duplicates skipped : %d\n", duplicates);
    printf("Tree height : %d\n", height(t));

    freeTree(t);   /* avoid memory leak */
    return 0;
}
