#include <stdio.h>
#include <stdlib.h>

#define N 4000
#define S 50000

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Tree {
    int data, height;
    struct Tree *left, *right;
} Tree;

int randomNum() {
    return 1000 + rand() % 9000;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int linear(int a[], int key) {
    for (int i = 0; i < N; i++)
        if (a[i] == key)
            return 1;
    return 0;
}

int binary(int a[], int key) {
    int l = 0, h = N - 1;

    while (l <= h) {
        int m = (l + h) / 2;

        if (a[m] == key)
            return 1;
        else if (a[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }

    return 0;
}

Node *listAdd(Node *head, int x) {
    Node *p = malloc(sizeof(Node));

    p->data = x;
    p->next = head;

    return p;
}

int listSearch(Node *head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1;

        head = head->next;
    }

    return 0;
}

Tree *newTree(int x) {
    Tree *p = malloc(sizeof(Tree));

    p->data = x;
    p->height = 1;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Tree *bstAdd(Tree *root, int x) {
    if (root == NULL)
        return newTree(x);

    if (x < root->data)
        root->left = bstAdd(root->left, x);
    else if (x > root->data)
        root->right = bstAdd(root->right, x);

    return root;
}

int height(Tree *p) {
    return p ? p->height : 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

Tree *rightRotate(Tree *y) {
    Tree *x = y->left;

    y->left = x->right;
    x->right = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Tree *leftRotate(Tree *x) {
    Tree *y = x->right;

    x->right = y->left;
    y->left = x;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Tree *avlAdd(Tree *root, int x) {
    if (root == NULL)
        return newTree(x);

    if (x < root->data)
        root->left = avlAdd(root->left, x);
    else if (x > root->data)
        root->right = avlAdd(root->right, x);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int b = height(root->left) - height(root->right);

    if (b > 1 && x < root->left->data)
        return rightRotate(root);

    if (b < -1 && x > root->right->data)
        return leftRotate(root);

    if (b > 1 && x > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && x < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int treeSearch(Tree *root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return 1;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

void freeList(Node *p) {
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

void freeTree(Tree *p) {
    if (p == NULL)
        return;

    freeTree(p->left);
    freeTree(p->right);
    free(p);
}

int main() {
    int a[N], b[N], key[S];
    Node *list = NULL;
    Tree *bst = NULL;
    Tree *avl = NULL;

    int s, f;

    for (int i = 0; i < N; i++) {
        a[i] = randomNum();
        b[i] = a[i];

        list = listAdd(list, a[i]);
        bst = bstAdd(bst, a[i]);
        avl = avlAdd(avl, a[i]);
    }

    qsort(b, N, sizeof(int), cmp);

    for (int i = 0; i < S; i++) {
        if (i % 2 == 0)
            key[i] = a[rand() % N];
        else
            key[i] = randomNum();
    }

    s = f = 0;

    for (int i = 0; i < S; i++) {
        if (linear(a, key[i]))
            s++;
        else
            f++;
    }

    printf("Unsorted Array : %d success, %d fail\n", s, f);

    s = f = 0;

    for (int i = 0; i < S; i++) {
        if (binary(b, key[i]))
            s++;
        else
            f++;
    }

    printf("Sorted Array   : %d success, %d fail\n", s, f);

    s = f = 0;

    for (int i = 0; i < S; i++) {
        if (listSearch(list, key[i]))
            s++;
        else
            f++;
    }

    printf("Linked List    : %d success, %d fail\n", s, f);

    s = f = 0;

    for (int i = 0; i < S; i++) {
        if (treeSearch(bst, key[i]))
            s++;
        else
            f++;
    }

    printf("BST            : %d success, %d fail\n", s, f);

    s = f = 0;

    for (int i = 0; i < S; i++) {
        if (treeSearch(avl, key[i]))
            s++;
        else
            f++;
    }

    printf("AVL Tree       : %d success, %d fail\n", s, f);

    freeList(list);
    freeTree(bst);
    freeTree(avl);

    return 0;
}
