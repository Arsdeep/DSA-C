#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int *val;
    int front,rear,size;
};

void show(struct queue*q)
{
    printf("\n");
    for(int i = q->front+1 ; i <= q->rear ; i++)
        printf("%d ",q->val[i]);
}

struct queue* init(int n)
{
    struct queue *temp = (struct queue*) malloc(sizeof(struct queue));
    temp->val = (int*) malloc(n*sizeof(int));
    temp->front = temp->rear = -1;
    temp->size = n;
}

void enqueue(struct queue*q,int n)
{
    if(q->rear < q->size)
        q->val[++q->rear] = n;
}

int dequeue(struct queue*q)
{
    if(q->front < q->rear)
        return q->val[++q->front];
}

void main()
{
    struct queue *q,*q2;
    q = init(10);
    q2 = init(10);

    for(int i = 1; i<=10 ; i++)
    {
        enqueue(q,i);
        enqueue(q2,11-i);
    }

    show(q);
    show(q2);

    printf("\n");
    for(int i = 1; i<=3 ; i++)
    printf("\nDequeued element - %d",dequeue(q));
    printf("\n");

    enqueue(q2,7);

    show(q);
    show(q2);
}

