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

struct Queue {
    int items[V];
    int front;
    int rear;
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

void bfs(struct Graph g, int startVertex) {
    int visited[V] = {0};
    struct Queue q;
    q.front = 0;
    q.rear = 0;

    visited[startVertex] = 1;
    q.items[q.rear++] = startVertex;

    while (q.front < q.rear) {
        int currentVertex = q.items[q.front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (g.matrix[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = 1;
                q.items[q.rear++] = i;
            }
        }
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
    printf("BFS Traversal of Graph 1 (starting from 0):\n");
    bfs(g1, 0);
    printf("\n");

    printf("Graph 2 Matrix:\n");
    printMatrix(g2);
    printf("Sorted Unique Edge Weights of Graph 2:\n");
    sortGraphWeights(g2);
    printf("BFS Traversal of Graph 2 (starting from 0):\n");
    bfs(g2, 0);

    return 0;
}

