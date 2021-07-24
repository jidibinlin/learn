#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
const int STACK_INCREMENT=10;

#define status int

typedef struct{
	int *base;
	int *top;
	int stacksize;
}stack;

status InitStack(stack *S);
status Push(stack *S,int ins);
int GetTop(stack *S);
status Pop(stack *S);
int main(void)
{
	stack S;
	S.stacksize=10;
	InitStack(&S);
	for(int i=0;i<10;i++)
		Push(&S,i);

	for(int i=0;i<10;i++)
	{
		Pop(&S);
		printf("%d\n",GetTop(&S));
	}
	return 0;
}

status InitStack(stack *S)
{
	S->base=(int *)malloc(S->stacksize*sizeof(int));
	if(S->base==NULL)//if S->base is NULL return -1
		exit(-1);
	S->top=S->base;
	return 0;
}

status Push(stack *S,int ins)
{
	if((S->top-S->base)>=S->stacksize)
	{
		S->base=(int *)realloc(S->base,(S->stacksize+STACK_INCREMENT)*sizeof(int));//reallow the size 
		if(!S->base) exit(-1);
		S->top=S->base+S->stacksize;
		S->stacksize+=STACK_INCREMENT;
	}
	*S->top++=ins;
	return 0;
}

int GetTop(stack *S)
{
	return *(S->top);
}

status Pop(stack *S)
{
	if(S->top==S->base) return -1;
	--S->top;
	return 0;
}
