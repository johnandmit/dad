#include <stdio.h>
#include <math.h>


int diff(int a, int b)
{
    return abs(a - b);
}

void minDis(int arr[], int n)
{
    int min = 9999, a, b;
    for (int i = 0; i < n-1; i++)
    {
        int temp = diff(arr[i], arr[i+1]);
        if (min > temp)
        {
            min = temp;
            a = arr[i];
            b = arr[i+1];
        }
    }
    printf("%i,%i\n", a, b);
}

int main()
{
    int n = 10;
    int arr[10] = {1,3,6,9,10,23,24,25,66,1000000};
    minDis(arr, n);
}
