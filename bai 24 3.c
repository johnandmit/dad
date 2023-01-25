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

treeNode *nodeFinder(int id, treeNode *node)
{
    if (node != NULL)
    {
        if (node->id == id)
        {
            return node;
        }
        treeNode *temp;
        temp = nodeFinder(id, node->left);
        if (temp != NULL && temp->id == id)
        {
            return temp;
        }
        temp = nodeFinder(id, node->right);
        if (temp != NULL && temp->id == id)
        {
            return temp;
        }
    }
    return NULL;
}

void thingy(treeNode *root, int k)
{
    if (root != NULL && k - root->id > 0)
    {
        treeNode *temp = nodeFinder(k - root->id, root);
        if (temp != NULL)
        {
            printf("%i + %i = %i", root->id, temp->id, k);
        }
        thingy(root->left, k);
        thingy(root->right, k);
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
    thingy(root, 9);
}
