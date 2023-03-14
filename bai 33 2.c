#include <stdio.h>
#include <stdlib.h>

int binaryMan(int arr[], int key, int start, int end)
{
    int min = start, max = end - 1, mid;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return -1;
}

int is3Arr(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int a1 = arr[i];
            int a2 = arr[j];
            int a3 = 2 * a2 - a1;
            if (binaryMan(arr, a3, j + 1, n) != -1)
            {
                printf("%i %i %i\n", a1, a2, a3);
            }
        }
    }
    return 0;
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int noSort3Arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a1 = arr[i];
            int a2 = arr[j];
            if (a1 < a2)
            {
                int a3 = 2 * a2 - a1;
                if (linearSearch(arr, n, a3) != -1)
                {
                    printf("%i %i %i\n", a1, a2, a3);
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n = 10;
    int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int arr2[10] = {-7, -4, -3, -1, 1, 4, 6, 8, 10, 12};
    is3Arr(arr2, n);
    printf("\n\n");
    noSort3Arr(arr, n);
    // printf("%i", noSort3Arr(arr, n));
}
