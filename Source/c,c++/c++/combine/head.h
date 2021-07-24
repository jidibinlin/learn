#pragma once
#define OVERFLOW -1
#define ERROR -1
#define OK 0
#include<iostream>
typedef int status;
typedef struct LNode{
public:
    int data;
    LNode *Next;
}LNode;

typedef LNode* Link;
typedef LNode* Position;

typedef struct{
    LNode *head,*tail;
    int len;
}Linklist;
status MakeNode(Link *p,int e);//分配由e指向的值为e的节点，并返回ok;若分配失败返回error
void FreeNode(Link p);//释放p所指节点
status InitList(Linklist *L);//构造一个空的线性链表L
status DestroyList(Linklist *L);//销毁线性链表L
status ClearList(Linklist *L);//将线性链表L重置为空表，并释放原链表的节点空间
status InsFirs(Link *h,Link *s,Linklist *L);//已知h指向线性链表的头节点，将s所指节点插入在第一个节点之前
status DelFirst(Link *h,Link *q,Linklist *L);//已知h指向线性链表的头节点，删除链表中的第一个节点并以q返回 
status Append(Linklist *L,Link *s);//将s指针所指的一串节点链接在线性链表L的最后一个节点之后，斌改变链表L的尾指针指向新的尾节点 
status Remove(Linklist *L,Link q);//删除线性表L中的尾节点并以q返回，改变链表L的尾指针指向新的尾节点
status InsBefore(Linklist *L,Link p,Link s);//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之前并修改指针p指向新插入的节点
status InsAfter(Linklist *L,Link p,Link s);//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之后并修改指针p指向新插入的节点
status SetCurElem(Link p,int e);//已知p指向线性表中的一个节点，用e更新p所指节点中数据元素的值
int GetCurElem(Link p);//已知p指向线性表中的一个节点，返回p所指节点的中元素的值
status ListEmpty(Linklist L);//若线性链表为空表，则返回true,否则返回false
int ListLength(Linklist L);//返回线性表L中元素个数
Position GetHead(Linklist L);//返回线性表L中头节点的位置
Position GetLast(Linklist L);//返回线性表L中最后一个节点的位置
Position PriorPos(Linklist L,Link p);//已知p指向线性表中的一个节点，返回p所指节点的直接前驱的位置 若无前驱则返回null
Position NextPos(Linklist L,Link p);//已知p指向线性表中的一个节点，返回p所指节点的直接后继的位置 若无前驱则返回null
status LocatePos(Linklist L,int i,Link *p);//返回p指示线性表L中第i个节点的位置并返回Ok，i值不合法时返回error
Position LocateElem(Linklist L,int e,status(*compare)(int,int));//返回线性链表L中第1个与e满足函数compare（）判定关系的元素的位置 若不存在这样的元素，则返回null
// status ListTraverse(Linklist L,status(*visit)());//依次对L的每一个元素调用visit（）。一旦visit（）失败，则操作失败
status compare(int first,int second);