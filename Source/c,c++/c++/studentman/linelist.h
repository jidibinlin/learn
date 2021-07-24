#pragma once
#define OVERFLOW -1
#define ERROR -1
#define OK 0
#include<iostream>
typedef int status;
typedef struct LNode{
public:
    int Snum;
    char Sname[8];
    int Sachi;
    LNode *Next;
}LNode;

typedef LNode* Link;
typedef LNode* Position;
struct Linklist{
private:
    LNode *head,*tail;
    int len;
    Link L;
public:    
LNode *p;
Linklist()//构造一个空的线性链表L      构造函数
    {
        LNode *p=new LNode;
        if(!p)
            exit(OVERFLOW);
        head=p;
        tail=p;
        len=0;
    }

~Linklist()//销毁线性链表L
    {
        ClearList();
        head=tail=NULL;
    }
status MakeNode(int Snum,char *Sname,int Sachi)//分配由p指向的值为e的节点，并返回ok;若分配失败返回error
    {
        p=new LNode;
        if(!p)
            return ERROR;
        p->Snum=Snum;
        *(p->Sname)=*Sname;
        p->Sachi=Sachi;
        return OK;
    }

void FreeNode(Link p)//释放p所指节点
    {
        delete p;
        p->Next=NULL;
    }

status DestroyList()//销毁线性链表L
    {
        ClearList();
        head=tail=NULL;
    }

status ClearList()//将线性链表L重置为空表，并释放原链表的节点空间
    {
        Link p,k;
        p=head;
        while(p!=tail)
        {
            k=p;
            p=p->Next;
            head=p;
            delete k; 
        }
        len=0;
        return OK;
    }

status InsFirs(Link *s)//已知h指向线性链表的头节点，将s所指节点插入在第一个节点之前
    {
        (*s)->Next=head;
        head=*s;
        len++;
        return OK;
    }
status DelFirst(Link *q)//已知h指向线性链表的头节点，删除链表中的第一个节点并以q返回
    { 
        Link k=head;
        (*q)->Snum=head->Snum;
        *((*q)->Sname)=*(head->Sname);
        (*q)->Sachi=head->Sachi;
        head=k->Next;
        FreeNode(k);

    }
status Append(Link *s)//将s指针所指的一串节点链接在线性链表L的最后一个节点之后，并改变链表L的尾指针指向新的尾节点
    {
        tail->Next=*s;
        do{
            *s=(*s)->Next;
            len++;
        }while(*s);
        tail=*s;
        return OK;
    }
status Remove(Link q)//删除线性表L中的尾节点并以q返回，改变链表L的尾指针指向新的尾节点
    {
        q->Snum=tail->Snum;
        *(q->Sname)=*(tail->Sname);
        q->Sachi=tail->Sachi;
        PriorPos(tail)->Next=NULL;
        FreeNode(tail);
        tail=GetLast();
        len--;
        return OK;
    }
status InsBefore(Link p,Link s)//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之前并修改指针p指向新插入的节点
    {
        s->Next=p;
        PriorPos(p)->Next=s;
        p=s;
        len++;
        return OK;
    }

status InsAfter(Link p,Link s)//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之后并修改指针p指向新插入的节点
    {
        s->Next=p->Next;
        p->Next=s;
        len++;
        p=s;
        return OK;
    }

status SetCurElem(Link p,int Snum,char *Sname,int Sachi)//已知p指向线性表中的一个节点，用e更新p所指节点中数据元素的值
    {
        p->Snum=Snum;
        *(p->Sname)=*Sname;
        p->Sachi=Sachi;
        return OK;
    }

status ListEmpty()//若线性链表为空表，则返回true,否则返回false
    {
        if(head==NULL)
            return true;
        return false;
    }

int ListLength()//返回线性表L中元素个数
    {
        return len;
    }

Position GetHead()//返回线性表L中头节点的位置
    {
        return head;
    }

Position GetLast()//返回线性表L中最后一个节点的位置
    {
        Link p=head;
        do{
            p=p->Next;
        }while(p->Next!=NULL);
        return p;
    }

Position PriorPos(Link p)//已知p指向线性表中的一个节点，返回p所指节点的直接前驱的位置 若无前驱则返回null
    {
        Link k=head;
        do{
            k=k->Next;
        }while(k->Next!=p);
        return k;
    }

Position NextPos(Link p)//已知p指向线性表中的一个节点，返回p所指节点的直接后继的位置 若无前驱则返回null
    {
        return p->Next;
    }

status LocatePos(int i,Link *p)//返回p指示线性表L中第i个节点的位置并返回Ok，i值不合法时返回error
    {
        *p=head;
        if(len<i)
            return false;
        for(int j=0;j<i-1;j++)
        {
            *p=(*p)->Next;
        }
        return OK;
    }

Position LocateElem(int Snum,char *Sname,int Sachi,status(*compare)(int,char*,int))//返回线性链表L中第1个与e满足函数compare（）判定关系的元素的位置 若不存在这样的元素，则返回null
    {
        Link k=head;
        while(compare(Snum,Sname,Sachi) && k!=tail)
            k=k->Next;
        return k;
    }

// status ListTraverse(Linklist L,status(*visit)())//依次对L的每一个元素调用visit（）。一旦visit（）失败，则操作失败
//     {
//         return OK;
//     }

};