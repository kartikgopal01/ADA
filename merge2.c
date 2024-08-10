#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for srand() and rand()
#include <time.h>   // Include time.h for time()

#define max 500000 // Set the maximum size of the array

int n, array[max];

void merge(int array[], int low, int mid, int high);

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int array[], int low, int mid, int high)
{   
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int l[n1], r[n2]; // Use arrays sized to the actual subarrays

    for (int i = 0; i < n1; i++)
    {
        l[i] = array[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            array[k++] = l[i++];
        }
        else
        {
            array[k++] = r[j++];
        }
    }

    while (i < n1)
    {
        array[k++] = l[i++];
    }
    while (j < n2)
    {
        array[k++] = r[j++];
    }
}

int main()
{   
    clock_t start, stop;
    double time_taken;

    printf("Enter the number of elements (n<500000): ");
    scanf("%d", &n);

     // seed the random number generator
    printf("Generating %d random elements...\n", n);
    for (int j = 0; j < n; j++)
    {
        array[j] = rand() % 100000; // generate random numbers between 0 and 99,999
    }

    start = clock();
    mergesort(0, n - 1);
    stop = clock();

    /* Uncomment this if you want to print the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
    */

    time_taken = (stop - start) / (double) CLOCKS_PER_SEC;
    printf("Total time taken = %lf milliseconds\n", time_taken * 1000);

    return 0;
}
