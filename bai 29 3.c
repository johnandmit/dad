#include <stdio.h>
#include <string.h>

int n = 11;

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(int arr[], int f, int m, int l)
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
        sort(arr, f, m, l);
    }
}

int partition(int arr[], int l, int r)
{
    int i = l+1, pivot = arr[l], j = r;
    while (i < j)
    {
        while (i <= r && arr[i] < pivot)
        {
            printf("e");
            i++;
        }
        while (j >= l && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[l], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

int *insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int last = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > last)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = last;
    }
}

void quickSort(int arr[], int l, int r)
{
    if (l - r < n)
    {
        insertion_sort(arr, n);
    }
    else
    {
        printf("e");
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int arr[11] = {30,19,24,28,41,34,15,43,20,12,36};
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
}
