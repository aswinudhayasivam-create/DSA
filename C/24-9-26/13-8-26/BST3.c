#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    int state;
    struct node *left, *right;
} BT;

BT *makeNode(char *data)
{
    BT *t = (BT *)malloc(sizeof(BT));
    strcpy(t->data, data);
    t->state = 1;
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
int search(BT *t, char *data)
{
    if (!t) return 0;
    if (t->data == data) return 1;
    if (t->data > data) return search(t->left, data);
    return search(t->right, data);

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
     return 0;
}

