#include<iostream>
#include"linelist.h"
using namespace std;
status compare(int x,int y)
{
	return x>=y? 1:0;
}
int main(void)
{
	Linklist *L=new Linklist;
	Linklist *L2=new Linklist;
	Linklist *L3;
	for(int i=1;i<10;i++)
    {
		L->MakeNode(i);
		L->InsFirs(&L->p);
    }
	for(int i=5;i<8;i++)
    {
		L2->MakeNode(i);
		L2->InsFirs(&L2->p);
    }
	
	LNode *pa,*pb;
	LNode *La,*Lb;
	La=L->GetHead();
	pa=L->NextPos(La);
	Lb=L2->GetHead();
	pb=L2->NextPos(Lb);
	while(pa && pb)
    {
		if(compare(pa->data,pb->data))
		{
			L3->Append(*pa);
			pa=pa->Next;
		}
    } 
	
	
	delete L;
	delete L2;
	return 0;
}

