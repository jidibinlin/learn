#include<stdio.h>
#include<malloc.h>
typedef struct linklist{
	int date;
	linklist *Next;
}*link,Node;

void init(link tmp);
void insert(link tmp,int i);
link intersect(link first,link second);

int main(void)
{
	link first=(link)malloc(sizeof(link));
	link second=(link)malloc(sizeof(link));
	for(int i=0;i<10;i++)
		insert(first,i);
	for(int i=3;i<7;i++)
		insert(second,i);
	link third=intersect(first,second);
	third=third->Next;
	while(third->Next!=NULL)
	{
		printf("%d ",third->date);
		third=third->Next;
	}

}

void insert(link tmp,int i)
{
	Node *tmpNode=(Node *)malloc(sizeof(Node));
	tmpNode->date=i;
	tmpNode->Next=NULL;
	Node *p;
	p=tmp;
	if(tmp->Next==NULL)
		tmp->Next=tmpNode;
	else
	{
		while(p->Next!=NULL)
			p=p->Next;
		p->Next=tmpNode;
	}

}

link intersect(link first,link second)
{
	link store=(link)malloc(sizeof(link));
	link p3=store;
	link p1=first->Next;
	link p2;
	while(p1->Next!=NULL)
	{
		p2=second->Next;
		while(p2->Next!=NULL)
		{
			p2=p2->Next;
			if(p1->date==p2->date)
			{
				p3->Next=(link)malloc(sizeof(link));
				p3->Next->date=p1->date;
				p3=p3->Next;
			}		
		}
		p1=p1->Next;
	}
	return store;

}
