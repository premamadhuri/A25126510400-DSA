#include <stdio.h>

int main()
{
    int a[100], n, i, j, key, shift = 0;

    printf("Enter the number of marks: ");
    scanf("%d", &n);

    printf("Enter the marks:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
            shift++;
        }

        a[j + 1] = key;

        printf("After pass %d: ", i);
        for(int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }

    printf("Sorted marks in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nTotal number of shifts = %d\n", shift);

    return 0;
}