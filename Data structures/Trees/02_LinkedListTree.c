#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    int val;
    struct Tree *right,*left;
};

void show(struct Tree * t)
{
    if(t != NULL)
    {
        printf("%d ",t->val);
        show(t->left);
        show(t->right);
    }
}

struct Tree * init(int n)
{
    struct Tree * tmp = (struct Tree*) malloc(sizeof(struct Tree));
    tmp->val = n;
    tmp->right = NULL;
    tmp->left = NULL;

    return tmp;
}

void insertRight(struct Tree *t, int n)
{
    if(t->right == NULL && n != -1)
    {
        struct Tree *temp = (struct Tree*) malloc(sizeof(struct Tree));
        temp->val = n;
        temp->right = NULL;
        temp->left = NULL;
        t->right = temp;
    }
}

void insertLeft(struct Tree *t, int n)
{
    if(t->left == NULL && n != -1)
    {
        struct Tree *temp = (struct Tree*) malloc(sizeof(struct Tree));
        temp->val = n;
        temp->right = NULL;
        temp->left = NULL;
        t->left = temp;
    }
}

void main()
{
    struct Tree *t = NULL;

    t = init(0);
    insertLeft(t,1);
    insertRight(t,2);

    show(t);
}