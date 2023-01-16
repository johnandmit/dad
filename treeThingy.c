#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
    int id;
    struct Tnode *LeftMostChild;
    struct Tnode *rightSibling;
};
typedef struct Tnode treeNode;

treeNode *Parent;

int isParent(treeNode *p, treeNode *n)
{
    if (p != NULL)
    {
        treeNode *temp = p->LeftMostChild;
        while (temp != NULL)
        {
            if (temp == n)
            {
                return 1;
            }
            temp = temp->rightSibling;
        }
    }
    return 0;
}

treeNode *parent(treeNode *T, treeNode *n)
{
    if(isParent(T,n))
    {
        Parent = T;
    }
    if (T != NULL)
    {
        parent(T->LeftMostChild, n);
        parent(T->rightSibling, n);
    }
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

    root->id = 0;  // a
    node1->id = 1; // b
    node2->id = 2; // c
    node3->id = 3; // d
    node4->id = 4; // e
    node5->id = 5; // f
    node6->id = 6; // g
    node7->id = 7; // h
    node8->id = 8; // i
    node9->id = 9; // j

    root->rightSibling = NULL;
    root->LeftMostChild = node1;

    node1->rightSibling = node2;
    node1->LeftMostChild = node3;

    node2->LeftMostChild = node5;
    node2->rightSibling = NULL;

    node3->rightSibling = node4;
    node3->LeftMostChild = NULL;

    node4->rightSibling = NULL;
    node4->LeftMostChild = NULL;

    node5->LeftMostChild = node6;
    node5->rightSibling = node9;

    node6->rightSibling = node7;
    node6->LeftMostChild = NULL;

    node7->rightSibling = node8;
    node7->LeftMostChild = NULL;

    node8->rightSibling = NULL;
    node8->LeftMostChild = NULL;

    node9->rightSibling = NULL;
    node9->LeftMostChild = NULL;

    parent(root, node8);
    printf("the parent of %i is %i",node8->id , Parent->id);
}
