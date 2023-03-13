#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
        else if (key > mid)
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
    int n = 1000;
    int arr[n];
    random_number(n,arr);
    int key = arr[70];

    printf("%i ",linearSearch(arr,n,key));

    printf("%i ",binaryMan(arr,n,key));

    printf("%i ",RECbinaryMan(arr,0,n,key));

}
