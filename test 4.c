#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numOfChar(char arr[],int n)
{
    int e=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='#')
        {
            e++;
        }
    }
    return e;
}

int isTree(char PreOrder[],int n)
{
    if(n-numOfChar(PreOrder,n)!=numOfChar(PreOrder,n))
    {
        return 0;
    }
    return 1;
}

int main()
{
    char PreOrder[13]={'9','3','4','#','#','1','#','#','2','#','6','#','#'};
    printf("%i",isTree(PreOrder,14));
}
