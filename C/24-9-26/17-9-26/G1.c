#include <stdio.h>
#include <stdlib.h>

#define V 4

struct Graph {
    int matrix[V][V];
};

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
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

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void sortGraphWeights(struct Graph g) {
    struct Node* root = NULL;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (g.matrix[i][j] != 0) {
                root = insert(root, g.matrix[i][j]);
            }
        }
    }
    inorder(root);
    printf("\n");
    freeTree(root);
}

void printMatrix(struct Graph g) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", g.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    struct Graph g1 = {
        .matrix = {
            {0, 5, 2, 0},
            {5, 0, 9, 0},
            {2, 9, 0, 7},
            {0, 0, 7, 0}
        }
    };

    struct Graph g2 = {
        .matrix = {
            {0, 3, 0, 0},
            {0, 0, 8, 0},
            {0, 0, 0, 4},
            {1, 0, 0, 0}
        }
    };

    printf("Graph 1 Matrix:\n");
    printMatrix(g1);
    printf("Sorted Unique Edge Weights of Graph 1:\n");
    sortGraphWeights(g1);
    printf("\n");

    printf("Graph 2 Matrix:\n");
    printMatrix(g2);
    printf("Sorted Unique Edge Weights of Graph 2:\n");
    sortGraphWeights(g2);

    return 0;
}
