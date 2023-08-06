#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void show(struct Node *h)
{
    struct Node *ptr = h;
    do
    {
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }while(ptr!=h);
    printf("\n");
}

struct Node* insnode(struct Node *h, int n)
{
    struct Node *ptr;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->val = n;
    ptr->next = h;

    struct Node *t = h;
    do
    {
        t = t->next;
    } while (t->next!=h);

    t->next = ptr;

    return ptr;
    
}


void main()
{
    struct Node *n;

    n = (struct Node*) malloc(sizeof(struct Node));

    n->val = 1;
    n->next = n;
    
    show(n);

    for(int i = 5; i>0 ; i--)
    n = insnode(n,i);

    show(n);
}