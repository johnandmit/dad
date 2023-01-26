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

int max(int a, int b) { return (a > b) ? a : b; }

int DepthOf(treeNode *n, treeNode *root, int depth)
{
    if (root != NULL)
    {
        if (root == n)
        {
            return depth;
        }
        int temp = DepthOf(n,root->left, depth + 1);
        if (temp != 0)
        {
            return temp;
        }
        temp = DepthOf(n,root->right, depth + 1);
        if (temp != 0)
        {
            return temp;
        }
    }
    return 0;
}

int cousinOf(treeNode *OG, treeNode *root, treeNode *x)
{
    if (root != NULL&&root!=x)
    {
        if (DepthOf(root, OG, 1) == DepthOf(x, OG, 1))
        {
            return 1;
        }
        if(cousinOf(OG,root->left,x))
        {
            printf("%i ", root->left->id);
        }
        if (cousinOf(OG,root->right, x))
        {
            printf("%i ", root->right->id);
        }
    }
    return 0;
}

int main()
{
    treeNode *root = makeTreeNode(1, NULL);
    treeNode *node1 = makeTreeNode(2, root);
    treeNode *node2 = makeTreeNode(3, root);
    treeNode *node3 = makeTreeNode(4, node1);
    treeNode *node4 = makeTreeNode(5, node1);
    treeNode *node5 = makeTreeNode(6, node2);
    cousinOf(root, root, node4);
}
