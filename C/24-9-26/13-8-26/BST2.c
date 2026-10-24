#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    int frequency;
    struct node *left, *right;
} BT;

BT *makeNode(int data)
{
    BT *t = (BT *)malloc(sizeof(BT));
    t->data = data;
    t->frequency = 1;
    t->left = t->right = NULL;
    return t;
}

void inOrder(BT *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("Value: %d  Frequency: %d\n", t->data, t->frequency);
        inOrder(t->right);
    }
}

BT *insert(BT *t, int data)
{
    if (!t) {

        return makeNode(data);
    }
    if (t->data > data)
        t->left = insert(t->left, data);
    else if (t->data < data)
        t->right = insert(t->right, data);
    else
        t->frequency++;

    return t;
}

int main()
{
     srand(time(NULL));
    BT *t = NULL;

    for (int i = 0; i < 500; i++) {
        int val = rand() % 10;

        t = insert(t, val);
    }

    printf("In-order values and frequencies:\n");
    inOrder(t);

    return 0;
}

















