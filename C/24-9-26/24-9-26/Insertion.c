#include <stdio.h>
void insertionSort(int a[], int n)
{
 int i, j, key;
 for (i = 1; i < n; i++)
 {
 key = a[i];
 j = i - 1;
 while (j >= 0 && a[j] > key)
 {
 a[j + 1] = a[j];
 j--;
 }
 a[j + 1] = key;
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
 insertionSort(a, n);
 printf("Sorted array:\n");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}
