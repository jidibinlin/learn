#include<iostream>
#include"head.h"
using namespace std;
int main(void)
{
    Linklist L;
    InitList(&L);
    for(int i=1;i<10;i++)
    {
        Link head;
        MakeNode(&head,i);
        InsFirs(&L.head,&head,&L);
        L.len=i;
    }
}

