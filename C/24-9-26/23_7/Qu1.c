#include <stdio.h>

#include <stdlib.h>

#define SIZE 5

int queue[SIZE];

int front = -1;

int rear = -1;

void insert(int value) {

    if (rear == SIZE - 1) {

        printf("Queue Overflow\n");

        return;

    }

    if (front == -1) {

        front = 0;

    }

    rear++;

    queue[rear] = value;

    printf("%d inserted\n", value);

}

void delete() {

    if (front == -1 || front > rear) {

        printf("Queue Underflow\n");

        return;

    }

    printf("%d deleted\n", queue[front]);

    front++;

    if (front > rear) {

        front = -1;

        rear = -1;

    }

}

void display() {

    if (front == -1) {

        printf("Queue is empty\n");

        return;

    }

    printf("Queue elements: ");

    for (int i = front; i <= rear; i++) {

        printf("%d ", queue[i]);

    }

    printf("\n");

}

int main() {

    int choice, value;

    while (1) {

        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter value: ");

                scanf("%d", &value);

                insert(value);

                break;

            case 2:

                delete();

                break;

            case 3:

                display();

                break;

            case 4:

                exit(0);

            default:

                printf("Invalid choice\n");

        }

    }

    return 0;

}


