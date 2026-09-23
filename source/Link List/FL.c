#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Utility function to create a new node
Node* createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Utility function to display the list
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 1. Count Total Nodes
int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 2. Search for an Element (Returns 1-based position or -1 if not found)
int search(Node *head, int key) {
    Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// 3. Reverse Linked List In-Place
void reverse(Node **head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// 4. Find Middle Node (Floyd's Fast & Slow Pointer Technique)
Node* findMiddle(Node *head) {
    if (head == NULL) return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // Returns pointer to middle node
}

// 5. Concatenate Two Linked Lists (Appends list2 to list1)
void concatenate(Node **head1, Node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    Node *temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

// 6. Detect Cycle / Loop (Floyd's Cycle Detection Algorithm)
int detectCycle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1; // Cycle exists
    }
    return 0; // No cycle
}

// 7. Remove Duplicates from a Sorted Linked List
void removeDuplicates(Node *head) {
    Node *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node *nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// 8. Merge Two Sorted Lists into One Sorted List
Node* mergeSorted(Node *l1, Node *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Node *result = NULL;
    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }
    return result;
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    // Creating List 1: 10 -> 20 -> 20 -> 30
    list1 = createNode(10);
    list1->next = createNode(20);
    list1->next->next = createNode(20);
    list1->next->next->next = createNode(30);

    printf("Original List 1: ");
    display(list1);

    // Demonstration 1: Node Count
    printf("Total Nodes: %d\n", countNodes(list1));

    // Demonstration 2: Search
    int pos = search(list1, 30);
    printf("Element 30 found at position: %d\n", pos);

    // Demonstration 3: Remove Duplicates
    removeDuplicates(list1);
    printf("After Removing Duplicates: ");
    display(list1);

    // Demonstration 4: Find Middle
    Node *mid = findMiddle(list1);
    if (mid) printf("Middle Node Data: %d\n", mid->data);

    // Demonstration 5: Reverse
    reverse(&list1);
    printf("Reversed List 1: ");
    display(list1);

    // Demonstration 6: Concatenation
    list2 = createNode(40);
    list2->next = createNode(50);
    concatenate(&list1, list2);
    printf("After Concatenation with List 2: ");
    display(list1);

    return 0;
}