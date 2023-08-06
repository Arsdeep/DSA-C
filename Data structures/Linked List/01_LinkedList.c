#include<stdio.h>
#include<stdlib.h>

struct list
{
    int val;
    struct list *next;
};

void show(struct list *l)
{
    printf("\n");
    while(l != NULL)
    {
        printf("%d ",l->val);
        l = l->next;
    }
}

void insert(struct list **l,int n)
{
    struct list *temp = (struct list*) malloc(sizeof(struct list));
    temp->val = n;
    temp->next = (*l);
    (*l) = temp;
}

void insertEnd(struct list *l,int n)
{
    struct list *iterator = l;
    while(iterator->next != NULL)
        iterator = iterator->next;

    struct list *temp = (struct list*) malloc(sizeof(struct list));
    temp->val = n;
    temp->next = NULL;
    iterator->next = temp;
}

void insertAt(struct list *l,int n,int i)
{
    struct list *iterator = l;
    while(iterator->next !=  NULL && --i>0)
        iterator = iterator->next;

    struct list *temp = (struct list*) malloc(sizeof(struct list));
    temp->val = n;
    temp->next = iterator->next;
    iterator->next = temp;
}

void insertBy(struct list *l,int n,int target)
{
    struct list *iterator = l;
    while(iterator->val != target && iterator != NULL)
        iterator = iterator->next;

    if(iterator == NULL)
        return;

    struct list *temp = (struct list*) malloc(sizeof(struct list));
    temp->val = n;
    temp->next = iterator->next;
    iterator->next = temp;
}

void delete(struct list **l)
{
    if((*l) == NULL)
        return;

    struct list *temp = (*l);
    (*l) = (*l)->next;
    free(temp);
}

void deleteEnd(struct list *l)
{
    if(l!=NULL)
    {
        if(l->next == NULL)
            free(l);
        else
        {
            struct list *i,*j;
            i = l;
            j = l->next;
            while(j->next != NULL)
            {
                i = i->next;
                j = j->next;
            }
            i->next = NULL;
            free(j);
        }
    }
}

void deleteAt(struct list *l,int i)
{
    struct list *iterator = l;
    while(iterator->next !=  NULL && --i>0)
        iterator = iterator->next;

    struct list *temp = iterator->next;

    iterator->next = temp->next;
    free(temp);
}

void deleteBy(struct list *l,int target)
{
    struct list *iterator = l;
    while(iterator->val != target && iterator != NULL)
        iterator = iterator->next;

    if(iterator == NULL)
        return;

    struct list *temp = iterator->next;
    iterator->next = temp->next;
    free(temp);
}

void main()
{
    struct list *l = NULL, *l2 = NULL;

    for(int i = 1 ; i <= 10 ; i++)
    {
        insert(&l,i);
        insert(&l2,11-i);
    }
    
    show(l);
    show(l2);
    printf("\n\n");

    insertEnd(l,0);
    
    show(l);
    show(l2);
    printf("\n\n");

    insertAt(l2,15,3);
    
    show(l);
    show(l2);
    printf("\n\n");

    insertBy(l2,93,7);
    
    show(l);
    show(l2);
    printf("\n\n");

    delete(&l2);

    show(l);
    show(l2);
    printf("\n\n");

    deleteEnd(l2);

    show(l);
    show(l2);
    printf("\n\n");

    deleteAt(l2,3);

    show(l);
    show(l2);
    printf("\n\n");

    deleteBy(l2,93);

    show(l);
    show(l2);
    printf("\n\n");
}