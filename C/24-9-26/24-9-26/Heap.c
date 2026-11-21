#include <stdio.h>
void swap(int *x, int *y)
{
 int temp = *x;
 *x = *y;
 *y = temp;
}
void heapify(int a[], int n, int i)
{
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < n && a[left] > a[largest])
 largest = left;
 if (right < n && a[right] > a[largest])
 largest = right;
 if (largest != i)
 {
 swap(&a[i], &a[largest]);
 heapify(a, n, largest);
 }
}
void heapSort(int a[], int n)
{
 int i;

 for (i = n / 2 - 1; i >= 0; i--)
 heapify(a, n, i);

 for (i = n - 1; i > 0; i--)
 {
 swap(&a[0], &a[i]);
 heapify(a, i, 0);
 }
}
int main()
{
 int a[100], n, i;
 printf("Enter number of elements: ");
 scanf("%d", &n);
 printf("Enter elements:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 heapSort(a, n);
 printf("Sorted array:\n");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}

