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
treeNode* reverse(treeNode *root)
{
    if(root!=NULL)
    {
        treeNode *temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        reverse(root->left);
        reverse(root->right);
    }
}

int PreOrder(treeNode *node)
{
    if (node == NULL)
        return 0;
    printf("%i ", node->id);
    PreOrder(node->left);
    PreOrder(node->right);
}

int main()
{
    treeNode *root = makeTreeNode(1, NULL);
    treeNode *node1 = makeTreeNode(2, root);
    treeNode *node2 = makeTreeNode(3, root);
    treeNode *node3 = makeTreeNode(4, node1);
    treeNode *node4 = makeTreeNode(5, node1);
    treeNode *node5 = makeTreeNode(6, node2);

    PreOrder(root);
    reverse(root);
    printf("\n\n");
    PreOrder(root);
}
