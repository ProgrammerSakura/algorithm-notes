#include<stdio.h>
#include<malloc.h>

//循环单链表的定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;


//初始化循环单链表
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); //建立一个头结点
    if(L == NULL)
        return false;
    L->next = L; //将头结点指向自己
    return true;
}

//判断循环链表是否为空
bool Empty(LinkList L)
{
    if(L->next == L)
        return true;
    else 
        return false;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode *p)
{
    if(p->next == L)
        return true;
    else 
        return false;
}
