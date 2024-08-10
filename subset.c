#include <stdio.h>

int w[10], x[10], d, n;

void sum_subset(int s, int k, int r) {
    int i;
    static int b = 1;
    x[k] = 1;
    if (s + w[k] == d) {
        printf("Subset %d: ", b++);
        for (i = 0; i <= k; i++) { 
            if (x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    } else if (s + w[k] + w[k + 1] <= d && k + 1 < n) { 
        sum_subset(s + w[k], k + 1, r - w[k]);
    }
    x[k] = 0;
    if (s + w[k + 1] <= d && k + 1 < n) {
        sum_subset(s, k + 1, r);
    }
}

int main() { 
    int i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("Enter the maximum subset sum: ");
    scanf("%d", &d);
    sum_subset(0, 0, sum);
    return 0;
}
