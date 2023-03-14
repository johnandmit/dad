#include <stdio.h>
#include <stdlib.h>

void random_number(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

// int is3Thing(int a, int b, int c)
// {
//     if (-1 *a == b && c > a)
//     {
//         return 1;
//     }
//     return 0;
// }

int is3Arr(int arr[], int n)
{
    int a=0,c=1;
    for (int i = 0; a<c; i++)
    {
        a=arr[i];
        c=arr[n-i-1];
        for(int j = i;j<n;j++)
        {
            if(a==arr[j]*-1)
            {
                return 1;
            }
        }
            
    }
    return 0;
}

int main()
{
    int n = 10;
    int arr[10]={-5,-4,-3,-1,0,2,3,5,8,10};
    // random_number(n, arr);

    printf("%i",is3Arr(arr,n));
}
