#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQ(Queue *q) {
    q->rear = -1;
    q->front = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = val;
    printf("Enqueued %d\n", val);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int val = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return val;
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", q->items[q->front]);
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQ(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    peek(&q);

    printf("Dequeued element is %d\n", dequeue(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    display(&q);

    return 0;
}