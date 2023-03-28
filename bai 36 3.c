#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree
{
    int key;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};
typedef struct BinarySearchTree node;

node *makeTreeNode(float inf)
{
    node *new = (node *)malloc(sizeof(node));

    new->key = inf;
    new->left = NULL;
    new->right = NULL;
}

node *insert(node *root, int key)
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

node *search(node *root, int key)
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

void printInorder(node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        printf("%i ", root->key);
        printInorder(root->right);
    }
}

node *findmin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *findmax(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *delete(node *root, int key)
{
    if (root == NULL)
    {
        printf("NO FOUND :'(  ;-; ");
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            node *temp = findmin(root->right);
            root->key = temp->key;
            root->right = delete (root->right, root->key);
        }
        else if (root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            root = NULL;
        }
    }
    return root;
}

int is_bst_rec(node *root)
{
    if (root->left != NULL && root->right != NULL && root != NULL)
    {
        if (root->key > root->right->key || root->key < root->left->key)
        {
            return 0;
        }
        int left = is_bst_rec(root->left);
        int right = is_bst_rec(root->right);

        if (left == 0 || right == 0)
        {
            return 0;
        }
        else if (left == 1 && right == 1)
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int is_bst(node *root)
{
    node *prevRight=root;
    node *temp2;
    while (1)
    {
        node *temp = prevRight;
        temp2 = prevRight;
        while (temp != NULL)
        {
            if (root->key > root->right->key || root->key < root->left->key)
            {
                return 0;
            }
            if (temp->right != NULL)
            {
                prevRight = temp->right;
            }
            temp = temp->left;
        }
        if (prevRight == temp2)
        {
            return 1;
        }
    }

}

int main()
{
    node *root = NULL;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 3);
    insert(root, 6);
    insert(root, 23);
    insert(root, 7);
    insert(root, 39);
    insert(root, 28);
    insert(root, 25);
    insert(root, 29);
    printInorder(root);
    printf("\n");

    printf("\n%i\n", is_bst(root));
}
