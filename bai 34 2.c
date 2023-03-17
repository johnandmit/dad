#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    int a=-1,b=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key&&a==-1)
        {
            a=i;
        }
        else if(arr[i]!=key&&a!=-1)
        {
            b=i-1;
            break;
        }
    }
    printf("%i %i",a,b);
}

int main()
{
    int nums[8] = {1,2,2,2,3,4,4,5}, target = 2;
    linearSearch(nums,8,target);
}
