#include <stdio.h>
#include <stdlib.h>

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

int LCA(treeNode *p, treeNode *q, treeNode *root)
{
    if (root != NULL)
    {
        int left = LCA(p, q, root->left);
        int right = LCA(p, q, root->right);
        if (left == -1 && right == -1)
        {
            return root->id;
        }
        if (left != -1 && left != -2)
        {
            return left;
        }
        else if (right != -1 && right != -2)
        {
            return right;
        }

        if (root == p)
        {
            return -1;
        }
        else if (root == q)
        {
            return -1;
        }
    }
    return -2;
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

    printf("e  %i", LCA(node3, node4, root));
}
