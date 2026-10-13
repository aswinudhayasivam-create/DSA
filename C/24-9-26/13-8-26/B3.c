#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
 typedef struct node {
    int data;
    int z;
    struct node *left, *right;
} BT;

BT *makeNode(int data)

{

    BT *t = (BT *)malloc(sizeof(BT));

    t->data = data;

    t->z = 1;

    t->left = t->right = NULL;

    return t;

}

void inOrder(BT *t)

{

    if (t)

    {

        inOrder(t->left);

        printf("Value: %d  Frequency: %d\n", t->data, t->z);

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

        t->z++;

    return t;

}

int main()

{

    BT *t = NULL;

    for (int i = 0; i < 500; i++) {

        t = insert(t, rand()%10);

    }

    printf("In-order values and frequencies:\n");

    inOrder(t);

    return 0;

}

