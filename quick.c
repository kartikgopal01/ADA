#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 30000

int a[MAX_SIZE], i, n;

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j)
    {
        while (i <= high && a[i] <= pivot) 
            i++;
        while (a[j] > pivot) 
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap pivot with element at j
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    int s;
   if (low < high)
    {
        s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int main()
{
    clock_t start, stop;
    double time;

    printf("Enter the array size n(less than 30000): ");
    scanf("%d", &n);
    
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        a[i] = rand() % 10000;

    /* printf("\nUnsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]); */

    start = clock();
    quicksort(a, 0, n - 1);
    stop = clock();

    time = (stop - start) / (double)CLOCKS_PER_SEC;
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nThe time taken to sort is %lf milliseconds\n", time * 1000);

    return 0;
}