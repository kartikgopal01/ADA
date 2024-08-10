#include <stdio.h>
#define max 10
int n, array[max];
void merge(int array[max], int low, int mid, int high);

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

void merge(int array[max], int low, int mid, int high)
{   
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = array[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k=low;
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            array[k++] = l[i++];
        }
        else
        {
            array[k++] = r[j++];
        }
    }

    for (; i < n1; i++)
    {
        array[k++] = l[i];
    }
    for (; j < n2; j++)
    {
        array[k++] = r[j];
    }
}

int main()
{
    printf("n:");
    scanf("%d", &n);

    printf("elements:");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &array[j]);
    }
    
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}