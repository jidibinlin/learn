#include<malloc.h>
#include<stdio.h>
#include<iostream>
#define MAXSIZE 10
#define status int
typedef struct queue{
	int *qBase;
	int rear;
	int front;
}*qu;

status EnQueue(qu q,int e);

status DeQueue(qu q);
	
int main(void)
{
	qu q=(qu)malloc(sizeof(qu));
	q->qBase=(int *)malloc(MAXSIZE*sizeof(int));
	q->front=q->rear=0;
	for(int i=0;i<10;i++)
	{
		EnQueue(q,i);
	}
	for(int i=0;i<10;i++)
	{
		DeQueue(q);
	}
	printf("\n");
	return 0;
}

status EnQueue(qu q,int e)
{
	if((q->rear+1)%MAXSIZE==q->front)
		return 1;
	q->qBase[q->rear]=e;
	q->rear=(q->rear+1)%MAXSIZE;
	return 0;
}

status DeQueue(qu q)
{
	if(q->front==q->rear)
		return 0;
	printf("%d ",q->front);
	q->front=(q->front+1)%MAXSIZE;
	return 1;
}
