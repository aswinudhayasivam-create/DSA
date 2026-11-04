#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct {
    int data[Max];
    int front;
    int rear;
} Queue;

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, int data) {
    q->data[q->rear++] = data;
}

int pop(Queue *q) {
    return q->data[q->front++];
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
       if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
