#include<stdio.h>

#define Max 100

typedef struct {
    int data[Max];
    int front;
    int rear;
} Queue;

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, int data) {
    q->data[q->rear++] = data;
}

int pop(Queue *q) {
    return q->data[q->front++];
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
            if (adj[u][v] == 1 && !vis[v]) {
                vis[v] = 1;
                push(&q, v);
            }
        }
    }
    printf("\n");
}

void dfshelper(int adj[Max][Max], int V, int u, int vis[]) {
    vis[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !vis[v]) {
            dfshelper(adj, V, v, vis);
        }
    }
}

void dfs(int adj[Max][Max], int V, int start) {
    int vis[Max] = {0};
    dfshelper(adj, V, start, vis);
    printf("\n");
}

void printAdjList(int adj[Max][Max], int V) {
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);

        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                printf("%d -> ", j);
            }
        }
        printf("null\n");
    }
}

int main() {
    int V1 = 4;
    int start1 = 0;
    int adj1[Max][Max] = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };

    int V2 = 3;
    int start2 = 1;
    int adj2[Max][Max] = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };

    printf("The Adjacency Matrix 1 is:\n");
    for (int i = 0; i < V1; i++) {
        for (int j = 0; j < V1; j++) {
            printf("%5d", adj1[i][j]);
        }
        printf("\n");
    }

    printf("BFS traversal: ");
    bfs(adj1, V1, start1);

    printf("DFS traversal: ");
    dfs(adj1, V1, start1);

    printf("The Adjacency List is:\n");
    printAdjList(adj1, V1);
    printf("\n");

    printf("The Adjacency Matrix 2 is:\n");
    for (int i = 0; i < V2; i++) {
        for (int j = 0; j < V2; j++) {
            printf("%5d", adj2[i][j]);
        }
        printf("\n");
    }

    printf("BFS traversal: ");
    bfs(adj2, V2, start2);

    return 0;
}
