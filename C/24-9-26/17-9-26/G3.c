
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
} ;

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

void sortGraph(int adj[Max][Max], int V) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] != 0) {
                root = insert(root, adj[i][j]);
            }
        }
    }
    inorder(root);
    printf("\n");
}

void bfs(int adj[Max][Max], int V, int start) {
    Queue q;
    int vis[Max] = {0};
    q.front = 0;
    q.rear = 0;

    push(&q, start);
    vis[start] = 1;

    while (!isEmpty(&q)) {
        int u = pop(&q);
        printf("%d ", u);
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !vis[v]) {
                vis[v] = 1;
                push(&q, v);
            }
        }
    }
    printf("\n");
}

int main() {
    int V1 = 6;
    int start1 = 0;
    int adj1[Max][Max] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 1, 0}
    };

    int V2 = 3;
    int start2 = 1;
    int adj2[Max][Max] = {
        {0, 3, 8},
        {3, 0, 0},
        {8, 0, 0}
    };

    printf("The Adjacency Matrix 1 is:\n");
    for (int i = 0; i < V1; i++) {
        for (int j = 0; j < V1; j++) {
            printf("%5d", adj1[i][j]);
        }
        printf("\n");
    }

    printf("Sorted Unique Elements of Graph 1: ");
    sortGraph(adj1, V1);

    printf("BFS traversal: ");
    bfs(adj1, V1, start1);
    printf("\n");

    printf("The Adjacency Matrix 2 is:\n");
    for (int i = 0; i < V2; i++) {
        for (int j = 0; j < V2; j++) {
            printf("%5d", adj2[i][j]);
        }
        printf("\n");
    }

    printf("Sorted Unique Elements of Graph 2: ");
    sortGraph(adj2, V2);

    printf("BFS traversal: ");
    bfs(adj2, V2, start2);

    return 0;
}
