#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct AVLTree
{
    int key;
    int height;
    struct AVLTree *left;
    struct AVLTree *right;
};
typedef struct AVLTree node;

node *makeTreeNode(float inf)
{
    node *new = (node *)malloc(sizeof(node));

    new->key = inf;
    new->height = 1;
    new->left = NULL;
    new->right = NULL;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int height(node *root)
{
    if (root != NULL)
    {

        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    return 0;
}

int getBalance(node *root)
{
    return height(root->left) - height(root->right);
}

node *leftRotate(node *k2)
{
    node *k1 = k2->right;
    node *B = k1->left;

    k1->left = k2;
    k2->right = B;

    k1->height = height(k1);
    k2->height = height(k2);

    return k1;
}

node *rightRotate(node *k1)
{
    node *k2 = k1->left;
    node *B = k2->right;

    k2->right = k1;
    k1->left = B;

    k1->height = height(k1);
    k2->height = height(k2);

    return k2;
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

int is_avl_rec(node *root)
{
    if (root->left != NULL && root->right != NULL && root != NULL)
    {
        if (abs(getBalance(root)) > 1)
        {
            return 0;
        }
        int left = is_avl_rec(root->left);
        int right = is_avl_rec(root->right);

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

int is_avl(node *root)
{
    node *prevRight = root;
    node *temp2;
    while (1)
    {
        node *temp = prevRight;
        temp2 = prevRight;
        while (temp != NULL)
        {
            if (abs(getBalance(temp)) > 1)
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

int is_bst_rec(node *root)
{
    if (root->left == NULL && root->right == NULL && root != NULL)
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

    printf("%i\n",is_avl_rec(root)&&is_bst_rec(root));
    printf("%i\n",is_avl(root)&&is_bst_rec(root));
}
