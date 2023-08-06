#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int *val;
    int size,top;
};

void show(struct stack*s)
{
    printf("\n");
    for(int i = s->top; i >= 0 ; i--)
    printf("%d ",s->val[i]);
};

struct stack* init(int n)
{
    struct stack *temp = (struct stack*) malloc(sizeof(struct stack));
    temp->val = (int*) malloc(n*sizeof(int));
    temp->size = n;
    temp->top = -1;
    return temp;
}

void push(struct stack *s,int n)
{
    if(s->top != s->size)
        s->val[++s->top] = n;
    else
        printf("\nStack Overflow");
}

int pop(struct stack *s)
{
    if(s->top != -1)
        return s->val[s->top--];
    else
    {
        printf("\nStack Underflow");
        return -1;
    }
}

int peek(struct stack *s)
{
    if(s->top != -1)
        return s->val[s->top];
    else
    {
        printf("\nStack Underflow");
        return -1;
    }
}

void main()
{
    struct stack *s,*s2;
    s = init(10);
    s2 = init(10);
    
    for(int i = 1 ; i<=10; i++)
    {
        push(s,i);
        push(s2,11-i);
    }

    show(s);
    show(s2);

    printf("\n\nPopping 3 numbers from stack 1 - ");
    for(int i = 1 ; i<=3; i++)
    {
        printf("%d,",pop(s));
    }
    printf("\b \n");

    show(s);
    show(s2);
}