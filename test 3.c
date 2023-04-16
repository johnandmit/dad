#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Tnode
{
    int id;
    struct Tnode *left;
    struct Tnode *right;
};
typedef struct Tnode treeNode;

treeNode *makeTreeNode(int x, treeNode *parent)
{
    treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
    temp->id = x;
    temp->left = NULL;
    temp->right = NULL;
    if (parent != NULL)
    {
        if (parent->left == NULL)
        {
            parent->left = temp;
        }
        else if (parent->right == NULL)
        {
            parent->right = temp;
        }
        else
        {
            printf("node with label %i can't have any more child", parent->id);
        }
    }
    return temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int Depth(treeNode *root)
{
    if (root != NULL)
    {
        return max(Depth(root->left), Depth(root->right)) + 1;
    }
    return 0;
}

int height(treeNode *root)
{
    if (root != NULL)
    {

        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    return 0;
}

void FindLayer(treeNode *root, int layer, int ogHeight, int arr[])
{
    if (root != NULL)
    {
        if (ogHeight - height(root) == layer)
        {
            int i = 0;
            for (; arr[i] != '\0'; i++)
                ;
            arr[i] = root->id;
            arr[i + 1] = '\0';
        }
        else
        {
            FindLayer(root->left, layer, ogHeight, arr);
            FindLayer(root->right, layer, ogHeight, arr);
        }
    }
}

treeNode *createNode(int info)
{
    treeNode *new = (treeNode *)malloc(sizeof(treeNode));
    new->id = info;
    new->left = NULL;
    new->right = NULL;
    return new;
}
treeNode *insert(treeNode *root, treeNode *node)
{
    if (root->right != NULL)
    {
        root->right = node;
    }
    else if (root->left != NULL)
    {
        root->left = node;
    }
    return root;
}

treeNode *search(treeNode *root, int key)
{
    if (root != NULL)
    {
        if (root->id == key)
        {
            return root;
        }
        else
        {
            treeNode *temp1 = search(root->left, key);
            treeNode *temp2 = search(root->right, key);
            if (temp1 != NULL)
            {
                return temp1;
            }
            else
            {
                return temp2;
            }
        }
    }
    return root;
}

int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int *TreeMaker(int inOrder[], int postOrder[], int arr[])
{
    int i;
    for (i = 0; postOrder[i + 1] != '\0'; i++)
        ;

    arr[0] = postOrder[i];

    for (int j = i - 1; j >= 0; j--)
    {
        int e = linearSearch(inOrder, i, postOrder[j]);
        int temp = linearSearch(arr, i * 2 + 1, postOrder[j]);
        if (e + 1 < j)
        {
            if (linearSearch(arr, i * 2 + 1, postOrder[j + 1 % i]) == -1)
            {
                arr[(temp + 1) * 2 + 1] = postOrder[j + 1 % i];
            }
            else
            {
                arr[(temp + 1) * 2 + 1] = -1;
            }
        }
        if (e - 1 >= 0)
        {
            if (linearSearch(arr, i * 2 + 1, postOrder[j + 1 % i]) == -1)
            {
                arr[(temp + 1) * 2] = postOrder[j - 1];
            }
            else
            {
                arr[(temp + 1) * 2] = -1;
            }
        }
    }
    return arr;
}

int main()
{
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node1 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node2 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node3 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node4 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node5 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node6 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node7 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node8 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node9 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node10 = (treeNode *)malloc(sizeof(treeNode));

    root->id = 0;  // a
    node1->id = 1; // b
    node2->id = 2; // c
    node3->id = 3; // d
    node4->id = 4; // e
    node5->id = 5; // f

    root->right = node2;
    root->left = node1;

    node1->right = node4;
    node1->left = node3;

    node2->left = node5;
    node2->right = NULL;

    node3->right = NULL;
    node3->left = NULL;

    node4->right = NULL;
    node4->left = NULL;

    node5->left = NULL;
    node5->right = NULL;

    int inOrder[5] = {9, 3, 15, 20, 7}, postOrder[5] = {9, 15, 7, 20, 3};

    int arr[100];

    TreeMaker(inOrder, postOrder, arr);
    for (int i = 0; i < 12; i++)
    {
        printf("%i ", arr[i]);
    }

    for (int i = 0; i < height(root); i++)
    {
        int arr[100];
        arr[0] = '\0';
        FindLayer(root, i, height(root), arr);
        for (int i = 0; arr[i] != '\0'; i++)
        {
            printf("%i ", arr[i]);
        }
        printf("\n");
    }
}
