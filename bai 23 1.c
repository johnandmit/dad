#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
    int id;
    struct Tnode *left;
    struct Tnode *right;
};
typedef struct Tnode treeNode;

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

int countNode(treeNode *root)
{
	if(root==NULL)
		return 0;
    if(root->left==NULL || root->right==NULL)
        return 1;
    int count = 0;
	count += countNode(root->left);
	count += countNode(root->right);
    return count;
}

int PreOrder(treeNode *node)
{
	if(node==NULL)
		return 0;
	printf("%i ",node->id);
	PreOrder(node->left);
	PreOrder(node->right);
}

int inOrder(treeNode *node)
{
	if(node==NULL)
		return 0;
	inOrder(node->left);
	printf("%i ",node->id);
	inOrder(node->right);
}

int postOrder(treeNode *node)
{
	if(node==NULL)
		return 0;
	postOrder(node->left);
	postOrder(node->right);
	printf("%i ",node->id);
}

int main()
{
    treeNode *root =  (treeNode*) malloc(sizeof(treeNode));
    treeNode *node1 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node2 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node3 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node4 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node5 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node6 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node7 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node8 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node9 = (treeNode*) malloc(sizeof(treeNode));
    treeNode *node10 = (treeNode*) malloc(sizeof(treeNode));

    root->id = 0;//a
    node1->id = 1;//b
    node2->id = 2;//c
    node3->id = 3;//d
    node4->id = 4;//e
    node5->id = 5;//f

    root->right = node2; root->left = node1;

    node1->right = node4; node1->left = node3;

    node2->left = node5; node2->right = NULL;

    node3->right = NULL; node3->left = NULL;

    node4->right = NULL; node4->left = NULL;

    node5->left = NULL; node5->right = NULL;

	printf("%i",countNode(root));
}
