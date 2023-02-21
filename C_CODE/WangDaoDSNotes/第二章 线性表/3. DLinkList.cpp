#include<stdio.h>
#include<malloc.h>

//双链表结点的定义
typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//双链表的初始化，带头结点
bool InitDouble(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    //判断是否分配成功
    if(L == NULL)
        return false;
    L->next = NULL;
    L->prior = NULL; //头结点的prior指针永远为NULL
    return true;
}

//判断双链表是否为空
/*
    思路：只需要判断头结点的next是否为空即可
*/
bool Empty(DLinkList L){
    if(L->next == NULL)
        return true; //为空
    else
        return false;//不为空
}

//双链表的插入操作
/*
    思路：
        1. 先进行判断插入的结点是否合法
        2. 再将s的指向p所指向的结点, 并判断p是否是最后一个结点
        3. 再将p所指向的结点的前置指针指向s结点
        4. 再将s结点的前置指针指向p
        5. 最后将p指向s
*/
bool InsertNextDNode(DNode *p, DNode *s)
{
    if(p == NULL && s == NULL)
        return false;
    s->next = p->next;
    if(p->next != NULL) //判断p还有没有后继结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//双链表的删除操作
/*
    思路：
        1. 先判断结点是否合法
        2. 定义一个指针指向p的下一个结点
        3. 将p指向q的下一个结点
        4. 判断q是否为最后一个结点，如果不是，则将q后的结点的前置指针指向p
        5. 释放指针q;
*/
//删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
    if(p == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    //判断q结点是不是最后一个结点
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

//双链表的销毁
/*
    思路：
        循环遍历链表，调用删除操作，将头结点后面的结点删除，最后释放头结点。
*/
bool DestroyList(DLinkList &L)
{
    while (L->next != NULL)
    {
        /* code */
        DeleteNextDNode(L);
    }
    free(L);//释放头结点
    L = NULL;//将头指针设为空
    
}

//双链表的遍历
bool ThrouthDNode(DNode *p){
    //后向遍历
    while (p != NULL)
    {
        /* code */
        p = p->next;
    }

    //前向遍历
    while (p != NULL)
    {
        /* code */
        p = p->prior;
    }
    
    //前向遍历跳过头结点
    while (p->prior != NULL)
    {
        /* code */
        p = p->prior;
    }
    
    
}