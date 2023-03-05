#include <stdio.h>
#include <string.h>

int n = 10;

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void merge(int arr[], int f, int m, int l)
{
    int first1 = f;
    int first2 = m + 1;
    int temp[l - f + 1];
    int i = 0;
    while (first1 <= m && first2 <= l)
    {
        if (arr[first1] < arr[first2])
        {
            temp[i] = arr[first1];
            first1++;
        }
        else
        {
            temp[i] = arr[first2];
            first2++;
        }
        i++;
    }
    while (first1 <= m)
    {
        temp[i] = arr[first1];
        first1++;
        i++;
    }
    while (first2 <= l)
    {
        temp[i] = arr[first2];
        first2++;
        i++;
    }
    for (int j = f; j <= l; j++)
    {
        arr[j] = temp[j - f];
    }
}

void mergeSort(int arr[], int f, int l)
{
    int m;
    if (f < l)
    {
        m = (f + l) / 2;
        mergeSort(arr, f, m);
        mergeSort(arr, m + 1, l);
        merge(arr, f, m, l);
    }
}

int main()
{
    int n = 15;
    int arr[15] = {22, 15, 36, 44, 10, 3, 9, 13, 29, 25, 65, 23, 1, -8, 2};
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
}
