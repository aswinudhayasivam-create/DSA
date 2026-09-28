#include <stdio.h>
#include <stdlib.h>

#define N 4000
#define S 50000

/* ==================== ARRAY ==================== */

int randomNumber()
{
    return 1000 + rand() % 9000;
}

void createArray(int arr[])
{
    for (int i = 0; i < N; i++)
        arr[i] = randomNumber();
}

void copyArray(int a[], int b[])
{
    for (int i = 0; i < N; i++)
        b[i] = a[i];
}

int linearSearch(int arr[], int key)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == key)
            return 1;
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binarySearch(int arr[], int key)
{
    int low = 0;
    int high = N - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}


/* ==================== LINKED LIST ==================== */

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

ListNode *insertList(ListNode *head, int value)
{
    ListNode *newNode = malloc(sizeof(ListNode));

    newNode->data = value;
    newNode->next = head;

    return newNode;
}

ListNode *createList(int arr[])
{
    ListNode *head = NULL;

    for (int i = 0; i < N; i++)
        head = insertList(head, arr[i]);

    return head;
}

int searchList(ListNode *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return 1;

        head = head->next;
    }

    return 0;
}

void freeList(ListNode *head)
{
    ListNode *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


/* ==================== BST ==================== */

typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *createBSTNode(int value)
{
    BSTNode *newNode = malloc(sizeof(BSTNode));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BSTNode *insertBST(BSTNode *root, int value)
{
    if (root == NULL)
        return createBSTNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);

    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

BSTNode *createBST(int arr[])
{
    BSTNode *root = NULL;

    for (int i = 0; i < N; i++)
        root = insertBST(root, arr[i]);

    return root;
}

int searchBST(BSTNode *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return 1;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

void freeBST(BSTNode *root)
{
    if (root == NULL)
        return;

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}


/* ==================== AVL TREE ==================== */

typedef struct AVLNode
{
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int height(AVLNode *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

AVLNode *createAVLNode(int value)
{
    AVLNode *newNode = malloc(sizeof(AVLNode));

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int balanceFactor(AVLNode *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

AVLNode *insertAVL(AVLNode *root, int value)
{
    if (root == NULL)
        return createAVLNode(value);

    if (value < root->data)
        root->left = insertAVL(root->left, value);

    else if (value > root->data)
        root->right = insertAVL(root->right, value);

    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balanceFactor(root);

    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLNode *createAVL(int arr[])
{
    AVLNode *root = NULL;

    for (int i = 0; i < N; i++)
        root = insertAVL(root, arr[i]);

    return root;
}

int searchAVL(AVLNode *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return 1;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

void freeAVL(AVLNode *root)
{
    if (root == NULL)
        return;

    freeAVL(root->left);
    freeAVL(root->right);
    free(root);
}


/* ==================== MAIN ==================== */

int main()
{
    int arr[N];
    int sortedArr[N];
    int keys[S];

    ListNode *list;
    BSTNode *bst;
    AVLNode *avl;

    int success, failure;

    srand(1);

    /* Create array */

    createArray(arr);

    /* Create sorted array */

    copyArray(arr, sortedArr);
    qsort(sortedArr, N, sizeof(int), compare);

    /* Create linked list */

    list = createList(arr);

    /* Create BST */

    bst = createBST(arr);

    /* Create AVL tree */

    avl = createAVL(arr);


    /* Create search keys */

    for (int i = 0; i < 40950; i++)
        keys[i] = arr[i % N];

    for (int i = 40950; i < S; i++)
    {
        int key;

        do
        {
            key = randomNumber();
        }
        while (linearSearch(arr, key));

        keys[i] = key;
    }


    /* ================= ARRAY ================= */

    success = 0;
    failure = 0;

    for (int i = 0; i < S; i++)
    {
        if (linearSearch(arr, keys[i]))
            success++;
        else
            failure++;
    }

    printf("Unsorted Array : %d success, %d fail\n",
           success, failure);


    /* ================= SORTED ARRAY ================= */

    success = 0;
    failure = 0;

    for (int i = 0; i < S; i++)
    {
        if (binarySearch(sortedArr, keys[i]))
            success++;
        else
            failure++;
    }

    printf("Sorted Array   : %d success, %d fail\n",
           success, failure);


    /* ================= LINKED LIST ================= */

    success = 0;
    failure = 0;

    for (int i = 0; i < S; i++)
    {
        if (searchList(list, keys[i]))
            success++;
        else
            failure++;
    }

    printf("Linked List    : %d success, %d fail\n",
           success, failure);


    /* ================= BST ================= */

    success = 0;
    failure = 0;

    for (int i = 0; i < S; i++)
    {
        if (searchBST(bst, keys[i]))
            success++;
        else
            failure++;
    }

    printf("BST            : %d success, %d fail\n",
           success, failure);


    /* ================= AVL TREE ================= */

    success = 0;
    failure = 0;

    for (int i = 0; i < S; i++)
    {
        if (searchAVL(avl, keys[i]))
            success++;
        else
            failure++;
    }

    printf("AVL Tree       : %d success, %d fail\n",
           success, failure);


    /* Free memory */

    freeList(list);
    freeBST(bst);
    freeAVL(avl);

    return 0;
}
