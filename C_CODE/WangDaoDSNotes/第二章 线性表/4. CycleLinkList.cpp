#include<stdio.h>
#include<malloc.h>

//ѭ��������Ķ���
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;


//��ʼ��ѭ��������
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); //����һ��ͷ���
    if(L == NULL)
        return false;
    L->next = L; //��ͷ���ָ���Լ�
    return true;
}

//�ж�ѭ�������Ƿ�Ϊ��
bool Empty(LinkList L)
{
    if(L->next == L)
        return true;
    else 
        return false;
}

//�жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool isTail(LinkList L, LNode *p)
{
    if(p->next == L)
        return true;
    else 
        return false;
}
