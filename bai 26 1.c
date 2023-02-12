#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    struct tnode *left;
    struct tnode *right;
    int frequency;
    char thingy;
};
typedef struct tnode node;

node *arr[500];
int n;

void remover(node *a[], int i)
{
    for (; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

void add(node *a[], node *new)
{
    a[n] = new;
    n++;
}

node *clone(int f[], char c[])
{
    int i;
    for (i = 0; f[i] != '\0'; i++)
    {
        arr[i] = (node *)malloc(sizeof(node));
        arr[i]->frequency = f[i];
        arr[i]->thingy = c[i];
        arr[i]->left=NULL;
        arr[i]->right=NULL;
    }
    arr[i] = (node *)malloc(sizeof(node));
    arr[i] = NULL;
    n = i;
}

int PreOrder(node *node,int step)
{
    if (node == NULL)
        return 0;
    if(node->thingy!=NULL)
    printf("%i,%c ,step:%i\n", node->frequency, node->thingy,step);
    step++;
    PreOrder(node->left,step);
    PreOrder(node->right,step);
}

void *huffman()
{
    if (n > 1)
    {
        printf("%i\n",n);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i]->frequency <= arr[x]->frequency && x != i)
            {
                y = x;
                x = i;
            }
        }
        if(x==y)
        {
            y++;
        }
        node *new = (node *)malloc(sizeof(node));
        new->right = arr[y];
        new->left = arr[x];
        new->thingy=NULL;
        new->frequency = arr[x]->frequency + arr[y]->frequency;
        if (x > y)
        {
            x--;
        }
        remover(arr, y);
        remover(arr, x);
        add(arr, new);
        huffman();
    }
    PreOrder(arr[0],0);
}


int main()
{
    int f[11];
    char c[11];

    f[11] = '\0';
    c[11] = '\0';

    c[0] = 'a';
    f[0] = 4;
    c[1] = ' ';
    f[1] = 4;
    c[2] = 'h';
    f[2] = 3;
    c[3] = 'o';
    f[3] = 3;
    c[4] = 'c';
    f[4] = 2;
    c[5] = 'i';
    f[5] = 2;
    c[6] = 'D';
    f[6] = 1;
    c[7] = 'K';
    f[7] = 1;
    c[8] = 'H';
    f[8] = 1;
    c[9] = 'B';
    f[9] = 1;
    c[10] = 'n';
    f[10] = 1;
    n=11;
    clone(f, c);
    huffman();
}
