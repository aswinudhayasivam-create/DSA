
#include<stdio.h>
#include<stdlib.h>

int Insertion(int A[],int n) {
    int Key;
    int j,i;
    int count = 0;
    for(i=1;i<n;i++) {
        Key = A[i];
        j = i-1;
        while(j>=0) {
            count++;
            if(A[j]>Key){
                A[j+1] = A[j];
                j--;
            }
            else
            {
                break;
            }
        }
        A[j+1] = Key;
    }
    printf("Sorted Array (Insertion):");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return count;
}

void merge(int A[], int l, int m, int h, int *count)
{
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[100];

    while(i <= m && j <= h)
    {
        (*count)++;
        if(A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    while(i <= m) {
        temp[k++] = A[i++];
    }

    while(j <= h) {
        temp[k++] = A[j++];
    }

    for(i = l, k = 0; i <= h; i++, k++) {
        A[i] = temp[k];
    }
}

void mSort(int A[], int l, int h, int *count)
{
    int m;
    if(l<h)
    {
        m = (l+h)/2;
        mSort(A,l,m,count);
        mSort(A,m+1,h,count);
        merge(A,l,m,h,count);
    }
}

int main() {
    int a[100], b[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
    }

    int z1 = Insertion(a, n);
    printf("Insertion Sort Count: %d\n\n", z1);

    int mergeCount = 0;
    mSort(b, 0, n - 1, &mergeCount);

    printf("Sorted Array (Merge Sort):");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
    printf("Merge Sort Count: %d\n", mergeCount);

    return 0;
}
