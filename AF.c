#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 1. Display Array
void display(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Insert Element at Specific Position (1-based index)
int insertAtPosition(int arr[], int size, int element, int pos) {
    if (size >= MAX) {
        printf("Array Overflow!\n");
        return size;
    }
    if (pos < 1 || pos > size + 1) {
        printf("Invalid Position!\n");
        return size;
    }
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    return size + 1;
}

// 3. Delete Element from Specific Position (1-based index)
int deleteAtPosition(int arr[], int size, int pos) {
    if (size <= 0) {
        printf("Array Underflow!\n");
        return size;
    }
    if (pos < 1 || pos > size) {
        printf("Invalid Position!\n");
        return size;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

// 4. Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i; // Returns 0-based index
    }
    return -1;
}

// 5. Binary Search (Requires Sorted Array)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// 6. Reverse Array In-Place
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

int main() {
    int arr[MAX] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original Array:\n");
    display(arr, size);

    // Insertion
    size = insertAtPosition(arr, size, 25, 3);
    printf("\nAfter Inserting 25 at Position 3:\n");
    display(arr, size);

    // Deletion
    size = deleteAtPosition(arr, size, 2);
    printf("\nAfter Deleting at Position 2:\n");
    display(arr, size);

    // Reversal
    reverseArray(arr, size);
    printf("\nAfter Reversing:\n");
    display(arr, size);

    // Search
    int pos = linearSearch(arr, size, 25);
    printf("\nElement 25 found at 0-based index: %d\n", pos);

    return 0;
}