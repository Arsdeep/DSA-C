#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int val;
    struct stack *next;
};

void show(struct stack*s)
{
    printf("\n");
    while(s != NULL)
    {
        printf("%d ",s->val);
        s = s->next;
    }  
}

void push(struct stack**s,int n)
{
    struct stack *temp = (struct stack*) malloc(sizeof(struct stack));
    temp->val = n;
    temp->next = (*s);
    (*s) = temp;
    return;
}

int pop(struct stack**s)
{
    if((*s) != NULL)
    {
        int n = (*s)->val;
        struct stack *temp = (*s);
        (*s) = (*s)->next;
        free(temp);
        return n;
    }
    else
        return -1;
}

void main()
{
    struct stack *s = NULL, *s2 = NULL;

    for(int i = 1; i<=10 ; i++)
    {
        push(&s,i);
        push(&s2,11-i);
    }

    show(s);
    show(s2);

    printf("\n\nPopping 3 numbers from stack 1 - ");

    for(int i = 1 ; i<=3; i++)
        printf("%d,",pop(&s));
    printf("\b \n");


    show(s);
    show(s2);
}