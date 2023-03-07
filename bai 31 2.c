#include <stdio.h>

// int isPrev(int prev[], int n, int key)
// {
//     for (int i = 0; i <= n; i++)
//     {
//         if (arr[i] = key)
//         {
//             return 1;
//         }
//     }
// }

int *removeDup(int arr[], int n)
{
    int yes[n], yI = 0, i;
    for (i = n; i >= 0; i--)
    {
        int e = i - 1;
        while (e >= 0 && arr[e] != arr[i])
        {
            e--;
        }
        if (e < 0)
        {
            yes[yI] = arr[i];
            yI++;
        }
        else
        {
            n--;
        }
    }
    n++;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            yes[yI] = arr[i];
            yI++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%i ", yes[i]);
    }
}

int main()
{
    int n = 10;
    int arr[10] = {1,3,5,1,3,2,6,7,5,3};
    removeDup(arr, n - 1);
}
