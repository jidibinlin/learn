 #include"head.h"
 status MakeNode(Link *p,int e)//分配由p指向的值为e的节点，并返回ok;若分配失败返回error
    {
        *p=new LNode;
        if(!p)
            return ERROR;
        (*p)->data=e;
        return OK;
    }

void FreeNode(Link p)//释放p所指节点
    {
        delete p;
        p->Next=NULL;
    }
status InitList(Linklist *L)//构造一个空的线性链表L
{
  LNode *p=new LNode;
  if(!p)
    exit(OVERFLOW);
  L->head=p;
  L->tail=p;
  L->len=0;
  return OK;
}

status DestroyList(Linklist *L)//销毁线性链表L
    {
        ClearList(L);
        L->len=0;
        L->head=L->tail=NULL;
        return OK;
    }

status ClearList(Linklist *L)//将线性链表L重置为空表，并释放原链表的节点空间
    {
        Link p,k;
        p=L->head;
        while(p!=L->tail)
        {
            k=p;
            p=p->Next;
            L->head=p;
            delete k;
        }
        L->len=0;
        return OK;
    }

status InsFirs(Link *h,Link *s,Linklist *L)//已知h指向线性链表的头节点，将s所指节点插入在第一个节点之前
    {
        (*s)->Next=*h;
        *h=*s;
        L->len++;
        return OK;
    }
status DelFirst(Link *h,Link *q,Linklist *L)//已知h指向线性链表的头节点，删除链表中的第一个节点并以q返回
    { 
        Link k=*h;
        (*q)->data=(*h)->Next->data;
        (*h)=(*h)->Next;
        L->len--;
        FreeNode(k);
        return OK;
    }
status Append(Linklist *L,Link *s)//将s指针所指的一串节点链接在线性链表L的最后一个节点之后，并改变链表L的尾指针指向新的尾节点
    {
        L->tail->Next=*s;
        do{
            *s=(*s)->Next;
            L->len++;
        }while(*s);
        L->tail=*s;
        return OK;
    }
status Remove(Linklist *L,Link q)//删除线性表L中的尾节点并以q返回，改变链表L的尾指针指向新的尾节点
    {
        q->data=(*L).tail->data;
        PriorPos(*L,(*L).tail)->Next=NULL;
        FreeNode((*L).tail);
        (*L).tail=GetLast(*L);
        L->len--;
        return OK;
    }
status InsBefore(Linklist *L,Link p,Link s)//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之前并修改指针p指向新插入的节点
    {
        s->Next=p;
        PriorPos(*L,p)->Next=s;
        p=s;
        L->len++;
        return OK;
    }

status InsAfter(Linklist *L,Link p,Link s)//已知p指向线性链表L中的一个节点，将s所指节点插入在p所指节点之后并修改指针p指向新插入的节点
    {
        s->Next=p->Next;
        p->Next=s;
        L->len++;
        p=s;
        return OK;
    }

status SetCurElem(Link p,int e)//已知p指向线性表中的一个节点，用e更新p所指节点中数据元素的值
    {
        p->data=e;
        return OK;
    }

int GetCurElem(Link p)//已知p指向线性表中的一个节点，返回p所指节点的中元素的值
    {
        return p->data;
    }

status ListEmpty(Linklist L)//若线性链表为空表，则返回true,否则返回false
    {
        if(L.head==NULL)
            return true;
        return false;
    }

int ListLength(Linklist L)//返回线性表L中元素个数
    {
        return L.len;
    }

Position GetHead(Linklist L)//返回线性表L中头节点的位置
    {
        return L.head;
    }

Position GetLast(Linklist L)//返回线性表L中最后一个节点的位置
    {
        Link p=L.head;
       do{
            p=p->Next;
        }while(p->Next!=NULL);
        return p;
    }

Position PriorPos(Linklist L,Link p)//已知p指向线性表中的一个节点，返回p所指节点的直接前驱的位置 若无前驱则返回null
    {
        Link k=L.head;
        do{
            k=k->Next;
        }while(k->Next!=p);
        return k;
    }

Position NextPos(Linklist L,Link p)//已知p指向线性表中的一个节点，返回p所指节点的直接后继的位置 若无前驱则返回null
    {
        return p->Next;
    }

status LocatePos(Linklist L,int i,Link *p)//返回p指示线性表L中第i个节点的位置并返回Ok，i值不合法时返回error
    {
        *p=L.head;
        if(L.len<i)
            return false;
        for(int j=0;j<i-1;j++)
        {
            *p=(*p)->Next;
        }
        return OK;
    }

Position LocateElem(Linklist L,int e,status(*compare)(int,int))//返回线性链表L中第1个与e满足函数compare（）判定关系的元素的位置 若不存在这样的元素，则返回null
    {
        Link k=L.head;
        while(compare(e,k->data) && k!=L.tail)
            k=k->Next;
        return k;
    }

// status ListTraverse(Linklist L,status(*visit)())//依次对L的每一个元素调用visit（）。一旦visit（）失败，则操作失败
//     {
//         return OK;
//     }

status compare(int first,int second)
    {
        return first==second? 0:1;
    }
