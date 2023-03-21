#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree
{
    int key;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};
typedef struct BinarySearchTree binaryTree;

binaryTree *makeTreeNode(float inf)
{
    binaryTree *new = (binaryTree *)malloc(sizeof(binaryTree));

    new->key = inf;
    new->left = NULL;
    new->right = NULL;
}

binaryTree *insert(binaryTree *root, int key)
{
    if (root == NULL)
    {
        root = makeTreeNode(key);
    }
    else
    {
        if (root->key > key)
        {
            root->left = insert(root->left, key);
        }
        else
        {
            root->right = insert(root->right, key);
        }
    }
    return root;
}

binaryTree *search(binaryTree *root, int key)
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            return root;
        }
        else
        {
            if (key > root->key)
            {
                return search(root->right, key);
            }
            else
            {
                return search(root->left, key);
            }
        }
    }
}

void printInorder(binaryTree *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        printf("%i ", root->key);
        printInorder(root->right);
    }
}

binaryTree *findmin(binaryTree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

binaryTree *findmax(binaryTree *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    binaryTree *root = NULL;
    root=insert(root, 12);
    // printf("%i ",root->key);
    insert(root, 5);
    insert(root, 6);
    insert(root, 8);
    insert(root, 10);

    // printf("%i",findmin(root)->key);
    printInorder(root);
}
