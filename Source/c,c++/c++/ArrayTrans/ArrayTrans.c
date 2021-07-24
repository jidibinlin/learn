#include<stdio.h>
typedef struct {
	int i,j;
	int e;
}Triple;

typedef struct {
	Triple data [16];
	int mu,nu,tu;
}TSMatrix;

int ElemLocate(TSMatrix *arry,int m,int n);

void display(TSMatrix * arry1);

void Transpose(TSMatrix * arry1,TSMatrix * arry2);

int main(void)
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
	Transpose(&arry1,&arry2);
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


void Transpose(TSMatrix * arry1,TSMatrix * arry2)
{
	arry2->tu=arry1->tu;
	arry2->mu=arry1->nu;
	arry2->nu=arry1->mu;
	if(arry2->tu)
	{
		int q=1;
		for(int col=0;col<arry1->nu;col++)
		{
			for(int p=0;p<arry1->tu;p++)
			{
				if(arry1->data[p].j==col)
				{
					arry2->data[q].i=arry1->data[p].j;
					arry2->data[q].j=arry1->data[p].i;
					arry2->data[q].e=arry1->data[p].e;
					q++;
				}
			}
		}
	}
	arry2=arry1;
}
