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

int FindPath(treeNode *find, treeNode *root, int arr[])
{
    if (root != NULL)
    {
        int i = 0;
        for (; arr[i] != '\0'; i++)
            ;
        arr[i] = root->id;
        arr[i + 1] = '\0';
        if(root==find)
        {
            return 0;
        }
        FindPath(find, root->left, arr);
        FindPath(find, root->right, arr);
    }
}

int LCA(treeNode* p,treeNode* q,treeNode* root)
{
    int arrP[100],arrQ[100];
    arrP[0]='\0';
    arrQ[0]='\0';
    FindPath(p,root,arrP);
    FindPath(q,root,arrQ);
    for(int i=0;arrP[i]!='\0'&&arrQ[i]!='\0';i++)
    {
        if(arrP[i+1]!=arrQ[i+1])
        {
            return arrP[i];
        }
    }

}

int main()
{
    treeNode *root = createNode(0);
    treeNode *node1 = createNode(1);
    treeNode *node2 = createNode(2);
    treeNode *node3 = createNode(3);
    treeNode *node4 = createNode(4);
    treeNode *node5 = createNode(5);
    treeNode *node6 = createNode(6);
    treeNode *node7 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node8 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node9 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node10 = (treeNode *)malloc(sizeof(treeNode));

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

    int arr[100];
    arr[0] = '\0';
    printf("e  %i", LCA(node3, node1, root));

    for (int i = 0; i < height(root); i++)
    {
        arr[0] = '\0';
        FindLayer(root, i, height(root), arr);
        for (int e = 0; arr[e] != '\0'; e++)
        {
            printf("%i ", arr[e]);
        }
        printf("\n");
    }
}
