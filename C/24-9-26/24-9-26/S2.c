#include <stdio.h>
#include <stdlib.h>

int merge_count = 0;

void display(int A[], int n, const char *algo_name, int count) {
    int i;
    printf("Sorted Array (%s): ", algo_name);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("%s Count: %d\n\n", algo_name, count);
}

int Insertion(int A[], int n) {
    int Key;
    int j, i;
    int count = 0;
    for (i = 1; i < n; i++) {
        Key = A[i];
        j = i - 1;
        while (j >= 0) {
            count++;
            if (A[j] > Key) {
                A[j + 1] = A[j];
                j--;
            } else {
                break;
            }
        }
        A[j + 1] = Key;
    }
    return count;
}

void merge(int A[], int l, int m, int h) {
       int i = l;
    int j = m + 1;
    int k = 0;
    int *temp = (int *)malloc((h - l + 1) * sizeof(int));

    while (i <= m && j <= h) {
        merge_count++;
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        temp[k] = A[i];
        i++;
        k++;
    }

    while (j <= h) {
        temp[k] = A[j];
        j++;
        k++;
    }

    for (i = 0; i < (h - l + 1); i++) {
        A[l + i] = temp[i];
    }

    free(temp);
}

void mSort(int A[], int l, int h) {
    int m;
    if (l < h) {
        m = (l + h) / 2;
        mSort(A, l, m);
        mSort(A, m + 1, h);
        merge(A, l, m, h);
    }
}

int main() {
    int a[100], b[100], n, i;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
    }

    int z = Insertion(a, n);
    display(a, n, "Insertion Sort", z);

    merge_count = 0;
    mSort(b, 0, n - 1);
    display(b, n, "Merge Sort", merge_count);

    return 0;
}

