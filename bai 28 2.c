#include <stdio.h>
#include <time.h>
#include<stdlib.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int* random_number(int n,int arr[])
{
    for(int i = 0;i<n;i++)
    {
        arr[i] = rand()*n+1;
    }
    return arr;
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

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

void bubbleMan(int arr[],int n)
{
    for(int i = n;i>=0;i--)
    {
        for(int j=1;j<i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}

int main()
{           
    int n = 19999;
    int arr[n];
    random_number(n,arr);
    clock_t time1=clock();
    insertion_sort(arr,10);
    time1=clock()-time1;
    float time_taken1 = ((float)time1)/CLOCKS_PER_SEC;

    clock_t time2=clock();
    selectionSort(arr, 10);
    time2=clock()-time2;
    float time_taken2 = ((float)time2)/CLOCKS_PER_SEC;

    clock_t time3=clock();
    bubbleMan(arr,n);
    time3=clock()-time3;
    float time_taken3 = ((float)time3)/CLOCKS_PER_SEC;
    printf("it took %f/100000 second to execute insertion sort\nit took %f/100000 second to execute selection sort\nit took %f/100000    second to execute bubble sort\n",time_taken1*100000,time_taken2*100000,time_taken3*100000);
    // for (int yes = 0; yes < n; yes++)
    // {
    //     printf("%i ", arr[yes]);
    // }
    // printf("\n");
}
