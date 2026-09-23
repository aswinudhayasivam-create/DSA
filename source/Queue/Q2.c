#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CQueue;

void initQ(CQueue *q) {
    q->rear = -1;
    q->front = -1;
}

int isFull(CQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CQueue *q) {
    return (q->front == -1);
}

void enqueue(CQueue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (q->rear == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = val;
    printf("Enqueued %d\n", val);
}

int dequeue(CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int val = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

void display(CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CQueue q;

    initQ(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    enqueue(&q, 60);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    return 0;
}