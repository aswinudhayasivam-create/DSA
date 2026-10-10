#include <stdio.h>
#include <stdlib.h>
 typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
 Node* createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
     newNode->data = value;
     newNode->left = NULL;
    newNode->right = NULL;
     return newNode;
}
 Node* insert(Node *root, int value)
{
    if (root == NULL)
        {
            return createNode(value);
    }
     if (value < root->data)
{
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
     return root;
}
 Node* search(Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
     if (value < root->data)

{
        return search(root->left, value);
    }
     return search(root->right, value);
}
 void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
 void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
 void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
 Node* findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
     return root;
}
 Node* findMax(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
     return root;
}
 int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
     return 1 + countNodes(root->left)

            + countNodes(root->right);
}
 int countLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
     if (root->left == NULL && root->right == NULL)
{
        return 1;
    }
     return countLeafNodes(root->left)

        + countLeafNodes(root->right);
}
 int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
     int leftHeight = height(root->left);
     int rightHeight = height(root->right);
     if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
 Node* deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
     if (value < root->data)
{
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
         if (root->right == NULL)

    {

        Node *temp = root->left;

        free(root);

        return temp;

    }

    Node *temp = findMin(root->right);

    root->data = temp->data;

    root->right = deleteNode(root->right, temp->data);

}
     return root;
}
 int main()
{
    Node *root = NULL;
     root = insert(root, 50);
     root = insert(root, 30);
     root = insert(root, 70);
     root = insert(root, 20);
     root = insert(root, 40);
     root = insert(root, 60);
     root = insert(root, 80);
     printf("Inorder: ");

     inorder(root);
     printf("\nPreorder: ");
     preorder(root);
     printf("\nPostorder: ");
    postorder(root);
     printf("\nTotal nodes = %d", countNodes(root));
    printf("\nLeaf nodes = %d", countLeafNodes(root));
    printf("\nHeight = %d", height(root));
     return 0;
}

