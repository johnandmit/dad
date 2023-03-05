#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Heapify(int arr[], int i, int n)
{
    i++;
    int left = i * 2-1, right = i * 2, big;
    i--;
    if (left <= n && arr[left] > arr[i])
    {
        big = left;
    }
    else
    {
        big = i;
    }
    if (right <= n && arr[right] > arr[big])
    {
        big = right;
    }
    if (big != i)
    {
        swap(&arr[i], &arr[big]);
        Heapify(arr, big, n);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void sort(int arr[],int n)
{
    buildHeap(arr,n);
    for(int i = n;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        Heapify(arr,0,i-1);
    }
}

int main()
{
    int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    sort(arr,9);
    // Heapify(arr, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", arr[i]);
    }
}
