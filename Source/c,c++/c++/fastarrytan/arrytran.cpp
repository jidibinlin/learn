#include<stdio.h>
typedef struct {
	int i,j;
	int e;
}Triple;

typedef struct {
	Triple data[16];
	int mu,nu,tu;
}TSMatrix;
int ElemLocate(TSMatrix * arry,int m,int n);

void display(TSMatrix * arry1);

TSMatrix fasttrans(TSMatrix * arry);

int main()
{
	TSMatrix arry1;
	TSMatrix arry2;
	arry1.mu=4;
	arry1.nu=4; 
	arry1.tu=3;
	arry2.mu=4;
	arry2.nu=4;
	arry2.tu=3;
	arry1.data[0].e=1;
	arry1.data[0].i=0;
	arry1.data[0].j=3;
	arry1.data[1].e=3;
	arry1.data[1].i=2;
	arry1.data[1].j=2;
	arry1.data[2].e=3;
	arry1.data[2].i=0; 
	arry1.data[2].j=1;
	display(&arry1);
	arry2=fasttrans(&arry1);
	printf("\n");
	display(&arry2);
}
int ElemLocate(TSMatrix * arry,int m,int n)
{
	for(int i=0;i<16;i++)
	{
		if(arry->data[i].i==m && arry->data[i].j==n)
			return i;
	}
	return -1;
}

void display(TSMatrix * arry1)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int pos=ElemLocate(arry1,i,j);
			if(pos!=-1)
				printf("%d ",arry1->data[pos].e);
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

TSMatrix fasttrans(TSMatrix * arry)
{
	TSMatrix arry2;
	arry2.tu=arry->tu;
	arry2.mu=arry->nu;
	arry2.nu=arry->mu;
	int num[4]={0};
	int cpot[4]={0};
	if(arry2.tu)
	{
		for(int t=0;t<arry2.tu;t++)
			num[arry->data[t].j]++;
		for(int t=1;t<arry->nu;t++)
			cpot[t]=cpot[t-1]+num[t-1];
	}
	int q;
	for(int i=0;i<arry->nu;i++)
	{
		int col=arry->data[i].j;
		q=cpot[col];
		arry2.data[i].e=arry->data[q].e;
		arry2.data[i].i=arry->data[q].j;
		arry2.data[i].j=arry->data[q].i;
	}
	return arry2;
}
