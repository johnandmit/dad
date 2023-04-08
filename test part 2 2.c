#include <stdio.h>
#include <stdlib.h>

struct _PointerType
{
    int inf;
    struct _PointerType *next;
};
typedef struct _PointerType PointerType;

PointerType *create(PointerType *dad, int info)
{
    PointerType *new = (PointerType *)malloc(sizeof(PointerType));

    new->inf = info;
    new->next = NULL;
    if (dad != NULL)
    {
        new->next = dad->next;
        dad->next = new;
    }

    return new;
}

PointerType *sort(PointerType *root1, PointerType *root2)
{
    PointerType *finalroot = create(NULL, 0);
    PointerType *temp = finalroot;
    while (root1 != NULL && root2 != NULL)
    {
        if (root1->inf > root2->inf)
        {
            temp->next = create(temp, root2->inf);
            root2 = root2->next;
        }
        else
        {
            temp->next = create(temp, root1->inf);
            root1 = root1->next;
        }
        temp = temp->next;
    }
    if (root1 != NULL)
    {
        while (root1 != NULL)
        {
            temp->next = create(temp, root1->inf);
            temp = temp->next;
            root1 = root1->next;
        }
    }
    else
    {
        while (root2 != NULL)
        {
            temp->next = create(temp, root2->inf);
            temp = temp->next;
            root2 = root2->next;
        }
    }
    return finalroot;
}

int main()
{
    PointerType *node1, *node2, *node3, *node4;
    PointerType *lnode1, *lnode2, *lnode3, *lnode4;

    node1 = create(NULL, 1);
    node2 = create(node1, 3);
    node3 = create(node2, 5);
    node4 = create(node3, 7);

    lnode1 = create(NULL, 2);
    lnode2 = create(lnode1, 4);
    lnode3 = create(lnode2, 6);
    lnode4 = create(lnode3, 8);

    PointerType *temp = sort(node1, lnode1)->next;
    while (temp != NULL)
    {
        printf("%i ", temp->inf);
        temp = temp->next;
    }
}
