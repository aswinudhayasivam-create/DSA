#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void findVerticesWithinK(struct Graph* graph, int startVertex, int K) {
    int numVertices = graph->numVertices;
    int* dist = malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        dist[i] = -1;
    }

    int* queue = malloc(numVertices * sizeof(int));
    int front = 0;
    int rear = 0;

    dist[startVertex] = 0;
    queue[rear++] = startVertex;

    printf("Vertices reachable from %d with at most distance %d:\n", startVertex, K);

    while (front < rear) {
        int currentVertex = queue[front++];

        if (dist[currentVertex] <= K) {
            printf("Vertex: %d, Distance: %d\n", currentVertex, dist[currentVertex]);
        } else {
            continue;
        }

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (dist[adjVertex] == -1) {
                dist[adjVertex] = dist[currentVertex] + 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(dist);
    free(queue);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    int source = 0;
    int K = 2;

    findVerticesWithinK(graph, source, K);

    return 0;
}
