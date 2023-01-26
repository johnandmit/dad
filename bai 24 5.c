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

void treePath(treeNode *leaf, treeNode *root, int total)
{
    if (root != NULL)
    {
        total += root->id;
        if (root == leaf)
        {
            printf("%i", total);
        }
        treePath(leaf, root->left, total);
        treePath(leaf, root->right, total);
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
    treePath(node4, root, 0);
}
