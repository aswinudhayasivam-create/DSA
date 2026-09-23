#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// Initialize Queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if Queue is Full
int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Check if Queue is Empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Enqueue Operation
void enqueue(CircularQueue *q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    printf("Enqueued: %d\n", val);
}

// Dequeue Operation
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = q->data[q->front];
    if (q->front == q->rear) { // Reset queue when last element is removed
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

// Peek Front Element
int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->data[q->front];
}

// Display Queue Contents
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue (Front to Rear): ");
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    display(&q);

    printf("Front Element (Peek): %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}