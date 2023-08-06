#include<stdio.h>
#include<stdlib.h>

struct Dlist
{
    int val;
    struct Dlist * next;
    struct Dlist * prev;
};

void showhead(struct Dlist *l)
{
    while(l!=NULL)
    {
        printf("%d ",l->val);
        l = l->next;
    }
}

void showtail(struct Dlist *l)
{
    while(l!=NULL)
    {
        printf("%d ",l->val);
        l = l->prev;
    }
}

void traverser(struct Dlist *l)
{
    char ch = 'a';

    while(ch != 'e')
    {
        printf("\n\nEnter which Node data u want to see previous/next - (p/n)");
        scanf("%c",&ch);

        if(ch == 'p')
        {
            if(l->prev != NULL)
            {
                l = l->prev;
                printf("\nData is - %d",l->val);
            }
            else printf("\nNode Doesn't Exist");
        }
        else if(ch == 'n')
        {
            if(l->next != NULL)
            {
                l = l->next;
                printf("\nData is - %d",l->val);
            }
            else printf("\nNode Doesn't Exist");
        }
        else if(ch == 'e') break;
    }
}


void insert(struct Dlist **l, int n)
{
    struct Dlist *temp = (struct Dlist*) malloc(sizeof(struct Dlist));
    temp->val = n;
    temp->next = (*l);
    if ((*l) != NULL) (*l)->prev = temp;
    temp->prev = NULL;
    (*l) = temp;
}


void main()
{
    struct Dlist * head = NULL;

    insert(&head,1);

    struct Dlist * tail = head;

    for(int i = 2; i<10 ;i++)
    insert(&head,i);

    showhead(head);
    printf("\n");
    showtail(tail);

    traverser(head);
}