#include <stdio.h>
#include <string.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int l, int r)
{
    int i = l, pivot = arr[l], j = r;
    while (i < j)
    {
        while (i <= r && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= l && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void insertion_sort(int arr[], int l,int r)
{
    for (int i = l; i <= r; i++)
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
    if(r-l<9)
    {
        insertion_sort(arr,l,r);
    }
    else
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}


int main()
{
    int n = 15;
    int arr[15] = {22, 15, 36, 44, 10, 3, 9, 13, 29, 25, 65, 23, 1, -8, 2};

    quickSort(arr, 0, n - 1);

    for (int i = 0; i <= 14; i++)
    {
        printf("%i ", arr[i]);
    }
}
