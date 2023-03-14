#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void random_number(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
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

int binaryMan(int arr[], int n, int key)
{
    int min = 0, max = n - 1, mid;
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

int RECbinaryMan(int arr[], int min, int max, int key)
{
    int mid = (max + min) / 2;
    if (min <= max)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return RECbinaryMan(arr, mid+1, max, key);
            
        }
        else
        {
            return RECbinaryMan(arr, min, mid-1, key);
        }
    }
    return -1;
}

int main()
{
    int n = 10;
    int arr[n];
    random_number(n,arr);
    mergeSort(arr,0,n);
    int key = arr[6];

    for(int i = 0;i<n;i++)
    {
        printf("%i ",arr[i]);
    }
    printf("\n\n");

    printf("%i ",linearSearch(arr,n,key));

    printf("%i ",binaryMan(arr,n,key));

    printf("%i ",RECbinaryMan(arr,0,n,key));

}
