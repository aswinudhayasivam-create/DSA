#include<stdio.h>
#define MAX 50

void traverse(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int *n, int pos, int value)
{
    if(*n>=MAX)
    {
        printf("Array is full\n");
        return;
    }
    if(pos<0 || pos>*n)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i=*n;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    (*n)++;
}
void delete(int arr[], int *n, int pos)
{
    if(*n<=0)
    {
        printf("Array is empty\n");
        return;
    }
    if(pos<0 || pos>=*n)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i=pos;i<*n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;

}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;   // found at index i
    return -1;          // not found
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}
void reverse(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}
void rotateLeft(int arr[], int n, int d) {
    int temp[MAX];
    for (int i = 0; i < n; i++)
        temp[i] = arr[(i + d) % n];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}
void merge(int a[], int m, int b[], int n, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
        result[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < m) result[k++] = a[i++];
    while (j < n) result[k++] = b[j++];
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int arr[MAX], n, choice, pos, value, key, result[MAX], m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Find Max\n");
        printf("7. Reverse\n");
        printf("8. Rotate Left\n");
        printf("9. Merge with another array\n");
        printf("10. Bubble Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insert(arr, &n, pos, value);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = linearSearch(arr, n, key);
                if (pos != -1) printf("Found at index %d\n", pos);
                else printf("Not found\n");
                break;
            case 5:
                bubbleSort(arr, n); // Ensure array is sorted for binary search
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = binarySearch(arr, n, key);
                if (pos != -1) printf("Found at index %d\n", pos);
                else printf("Not found\n");
                break;
            case 6:
                value = findMax(arr, n);
                printf("Max value is %d\n", value);
                break;
            case 7:
                reverse(arr, n);
                break;
            case 8:
                printf("Enter number of positions to rotate left: ");
                scanf("%d", &value);
                rotateLeft(arr, n, value);
                break;
            case 9:
                printf("Enter number of elements in second array: ");
                scanf("%d", &m);
                int arr2[MAX];
                printf("Enter elements of second array:\n");
                for (int i = 0; i < m; i++)
                    scanf("%d", &arr2[i]);
                merge(arr, n, arr2, m, result);
                printf("Merged array: ");
                traverse(result, n + m);
                break;
            case 10:
                bubbleSort(arr, n);
                printf("Sorted array: ");
                traverse(arr, n);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}