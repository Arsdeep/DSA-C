#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int val;
    struct tree *left,*right;
};

void show(struct tree *t)
{
    if(t != NULL)
    {
        printf("%d ",t->val);
        show(t->left);
        show(t->right);
    }
}

struct tree* LinkedTreefromArr(struct tree *t, int *arr, int n, int i)
{
    if (i >= n) {
        return NULL;
    }

    if(arr[i] == -1)
        t = NULL;
    else
    {
    struct tree *temp = (struct tree*) malloc(sizeof(struct tree));  
    temp->right = NULL;
    temp->left = NULL;

    temp->val = arr[i];

    t = temp;

    t->left = LinkedTreefromArr(t->left, arr, n, 2*i+1);
    t->right = LinkedTreefromArr(t->right, arr, n, 2*i+2);
    }

    return t;
}


void main()
{
    int arr[] = {1,2,3,4,5,-1,7,8,9,10};       // -1 represents No Child
    //              1
    //         2         3
    //      4    5   (-1)    7
    //   8  9  10

    int n = sizeof(arr)/sizeof(int);

    struct tree *t;

    t = LinkedTreefromArr(t,arr,n,0);

    show(t);
}