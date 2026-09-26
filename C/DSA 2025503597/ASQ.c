#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ==========================================
// 1. ARRAY OPERATIONS
// ==========================================

// Display Array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert Element at Specific Position (1-based index)
int insertAtPosition(int arr[], int size, int element, int pos) {
    if (size >= MAX) {
        printf("Array is Full!\n");
        return size;
    }
    if (pos < 1 || pos > size + 1) {
        printf("Invalid Position!\n");
        return size;
    }
    // Shift elements to the right
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    return size + 1;
}

// Delete Element from Specific Position (1-based index)
int deleteAtPosition(int arr[], int size, int pos) {
    if (size <= 0) {
        printf("Array is Empty!\n");
        return size;
    }
    if (pos < 1 || pos > size) {
        printf("Invalid Position!\n");
        return size;
    }
    // Shift elements to the left
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

// Binary Search (Requires Sorted Array)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid; // Returns 0-based index
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

// Reverse Array In-Place
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// ==========================================
// 2. STACK OPERATIONS (Array-Based)
// ==========================================

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (isStackFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (isStackEmpty(s)) return -1;
    return s->data[s->top];
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// ==========================================
// 3. QUEUE OPERATIONS (Circular Array-Based)
// ==========================================

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isQueueEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int val) {
    if (isQueueFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}

int dequeue(CircularQueue *q) {
    if (isQueueEmpty(q)) {
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

void displayQueue(CircularQueue *q) {
    if (isQueueEmpty(q)) {
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

// ==========================================
// MAIN FUNCTION (Demonstration)
// ==========================================

int main() {
    // --- 1. ARRAY DEMO ---
    printf("--- 1. ARRAY DEMO ---\n");
    int arr[MAX] = {10, 20, 30, 40, 50};
    int size = 5;

    displayArray(arr, size);
    
    size = insertAtPosition(arr, size, 25, 3); // Insert 25 at 3rd position
    printf("After Inserting 25 at Pos 3: ");
    displayArray(arr, size);

    size = deleteAtPosition(arr, size, 2); // Delete element at 2nd position
    printf("After Deleting at Pos 2: ");
    displayArray(arr, size);

    reverseArray(arr, size);
    printf("Reversed Array: ");
    displayArray(arr, size);

    // --- 2. STACK DEMO ---
    printf("\n--- 2. STACK DEMO ---\n");
    Stack s;
    initStack(&s);

    push(&s, 100);
    push(&s, 200);
    push(&s, 300);
    displayStack(&s);

    printf("Top Element (Peek): %d\n", peek(&s));
    printf("Popped Element: %d\n", pop(&s));
    displayStack(&s);

    // --- 3. QUEUE DEMO ---
    printf("\n--- 3. CIRCULAR QUEUE DEMO ---\n");
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    displayQueue(&q);

    printf("Dequeued Element: %d\n", dequeue(&q));
    displayQueue(&q);

    return 0;
}