#include<iostream>
#include<stdlib.h>
#include"head.h"

using namespace std;

int main(void)
{
	Linklist L1,L2;
	Link temp;
	InitList(&L1);
	InitList(&L2);
	for(int i=0;i<10;i+=2)
	{
		MakeNode(&temp,i);
		InsAfter(&L1,(L1.tail),temp);
	}
	for(int i=0;i<10;i++)
	{
		MakeNode(&temp,i);
		InsAfter(&L2,L2.tail,temp);
	}
	Link p1,p2,p3;
	Linklist L3;
	InitList(&L3);
	p1=GetHead(L1)->Next;
	p2=GetHead(L2)->Next;
	p3=L3.head=GetHead(L1);
	while(p1&&p2)
	{
		if(compare(p1->data,p2->data))
		{
			p3->Next=p1;
			p3=p1;
			p1=p1->Next;
		}
		else{
			p3->Next=p2;
			p3=p2;
			p2=p2->Next;
		}
	}
	p3->Next=p1? p1:p2;
	return 0;
}  
