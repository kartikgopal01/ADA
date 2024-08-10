#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectsort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int a[30000], n, i;
    clock_t start, stop;
    double time;

    // Input the size of the array
    printf("Enter the array size n: ");
    scanf("%d", &n);

    // Generate random elements for the array
    printf("Generating random array elements...\n");
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    // Print the unsorted array
    // printf("Unsorted array: ");
    // for (i = 0; i < n; i++)
    //     printf("%d ", a[i]);

    // Start the clock and sort the array using selection sort
    start = clock();
    selectsort(a, n);
    stop = clock();

    // Calculate and print the time taken for sorting
    time = (double)(stop - start) / CLOCKS_PER_SEC;
    // printf("\nSorted array: ");
    // for (i = 0; i < n; i++)
    //     printf("%d ", a[i]);
    printf("\nThe time taken to sort is %lf milliseconds\n", time * 1000);

    return 0;
}
