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

treeNode *nodeFinder(int id, treeNode *root)
{
    if (root != NULL)
    {
        if (root->id == id)
        {
            return root;
        }
        treeNode *temp;
        temp = nodeFinder(id, root->left);
        if (temp != NULL && temp->id == id)
        {
            return temp;
        }
        temp = nodeFinder(id, root->right);
        if (temp != NULL && temp->id == id)
        {
            return temp;
        }
    }
    return NULL;
}

int thingy(treeNode *root, int k, treeNode *OG)
{
    if (root != NULL && k - root->id > 0 && root->id*2 != k)
    {
        treeNode *temp = nodeFinder(k - root->id, OG);
        if (temp != NULL)
        {
            printf("%i + %i = %i\n", root->id, temp->id, k);
        }
        thingy(root->left, k,OG);
        thingy(root->right, k,OG);
    }
}

int main()
{
    treeNode *root = makeTreeNode(1, NULL);
    treeNode *node1 = makeTreeNode(2, root);
    treeNode *node2 = makeTreeNode(3, root);
    treeNode *node3 = makeTreeNode(4, node1);
    treeNode *node4 = makeTreeNode(5, node1);
    treeNode *node5 = makeTreeNode(6, node2);
    thingy(root, 6,root);
}
