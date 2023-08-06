#include<stdio.h>
#include<stdlib.h>

int getLeftChild(int *t,int i,int n)
{
    if(i*2+1<n && t[i*2+1] != -1)
        return i*2+1;
    else
        return -1;
}

int getRightChild(int *t,int i,int n)
{
    if(i*2+2<n && t[i*2+2] != -1)
        return i*2+2;
    else
        return -1;
}

void inorderTraversal(int *t,int i,int n)
{
    if(i != -1 && i<n)
    {
        inorderTraversal(t,getLeftChild(t,i,n),n);
        printf("%d ",t[i]);
        inorderTraversal(t,getRightChild(t,i,n),n);
    }
}

void preorderTraversal(int *t,int i,int n)
{
    if(i != -1 && i<n)
    {
        printf("%d ",t[i]);
        preorderTraversal(t,getLeftChild(t,i,n),n);
        preorderTraversal(t,getRightChild(t,i,n),n);
    }
}
void postorderTraversal(int *t,int i,int n)
{
    if(i != -1 && i<n)
    {
        postorderTraversal(t,getLeftChild(t,i,n),n);
        postorderTraversal(t,getRightChild(t,i,n),n);
        printf("%d ",t[i]);
    }
}
void main()
{
    int t[] = {1,2,3,4,5,6,7,8,9,10};
    //             1
    //         2       3
    //      4    5   6    7
    //   8  9  10
    int n = sizeof(t)/sizeof(int);

    printf("\nIn-ordered Traversal - ");
    inorderTraversal(t,0,n);
    printf("\n");

    printf("\nPre-ordered Traversal - ");
    preorderTraversal(t,0,n);
    printf("\n");

    printf("\nPost-ordered Traversal - ");
    postorderTraversal(t,0,n);
    printf("\n");
    printf("\n");
}