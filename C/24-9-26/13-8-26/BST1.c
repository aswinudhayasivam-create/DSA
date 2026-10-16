#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    struct node *left, *right;
} BT;

BT *makeNode(char *data)
{
    BT *t = (BT *)malloc(sizeof(BT));
    strcpy(t->data, data);
    t->left = t->right = NULL;
    return t;
}

void inOrder(BT *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%s ", t->data);
        inOrder(t->right);
    }
}

BT *insert(BT *t, char *data)
{
    if (!t) {
        return makeNode(data);
    }
    if (strcmp(t->data, data) > 0)
        t->left = insert(t->left, data);
    else if (strcmp(t->data, data) < 0)
        t->right = insert(t->right, data);

    return t;
}

int count(BT *t)
{
    if (!t) return 0;
    return 1 + count(t->left) + count(t->right);
}

int leafCount(BT *t)
{
    if (!t) return 0;
    if (!t->left && !t->right) return 1;
    return leafCount(t->left) + leafCount(t->right);
}

int oneChild(BT *t)
{
    if (!t) return 0;
    int count = 0;
    if ((t->left && !t->right) || (!t->left && t->right))
        count = 1;
    return count + oneChild(t->left) + oneChild(t->right);
}

int twoChild(BT *t)
{
    if (!t) return 0;
    int count = 0;
    if (t->left && t->right)
        count = 1;
    return count + twoChild(t->left) + twoChild(t->right);
}

int main()
{
    BT *t = NULL;
    int n;
    char data[100];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++)
    {
        printf("Enter string: ");
        scanf("%99s", data);
        t = insert(t, data);
    }

    printf("\nIn-order values:\n");
    inOrder(t);
    printf("\n");

    printf("Node count : %d\n", count(t));
    printf("\nNumber of leaf nodes = %d", leafCount(t));
    printf("\nNumber of nodes with 1 child = %d", oneChild(t));
    printf("\nNumber of nodes with 2 children = %d\n", twoChild(t));

    return 0;
}
