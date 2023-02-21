#include<stdio.h>
#include<malloc.h>

//˫������Ķ���
typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//˫����ĳ�ʼ������ͷ���
bool InitDouble(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    //�ж��Ƿ����ɹ�
    if(L == NULL)
        return false;
    L->next = NULL;
    L->prior = NULL; //ͷ����priorָ����ԶΪNULL
    return true;
}

//�ж�˫�����Ƿ�Ϊ��
/*
    ˼·��ֻ��Ҫ�ж�ͷ����next�Ƿ�Ϊ�ռ���
*/
bool Empty(DLinkList L){
    if(L->next == NULL)
        return true; //Ϊ��
    else
        return false;//��Ϊ��
}

//˫����Ĳ������
/*
    ˼·��
        1. �Ƚ����жϲ���Ľ���Ƿ�Ϸ�
        2. �ٽ�s��ָ��p��ָ��Ľ��, ���ж�p�Ƿ������һ�����
        3. �ٽ�p��ָ��Ľ���ǰ��ָ��ָ��s���
        4. �ٽ�s����ǰ��ָ��ָ��p
        5. ���pָ��s
*/
bool InsertNextDNode(DNode *p, DNode *s)
{
    if(p == NULL && s == NULL)
        return false;
    s->next = p->next;
    if(p->next != NULL) //�ж�p����û�к�̽��
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//˫�����ɾ������
/*
    ˼·��
        1. ���жϽ���Ƿ�Ϸ�
        2. ����һ��ָ��ָ��p����һ�����
        3. ��pָ��q����һ�����
        4. �ж�q�Ƿ�Ϊ���һ����㣬������ǣ���q��Ľ���ǰ��ָ��ָ��p
        5. �ͷ�ָ��q;
*/
//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p)
{
    if(p == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    //�ж�q����ǲ������һ�����
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

//˫���������
/*
    ˼·��
        ѭ��������������ɾ����������ͷ������Ľ��ɾ��������ͷ�ͷ��㡣
*/
bool DestroyList(DLinkList &L)
{
    while (L->next != NULL)
    {
        /* code */
        DeleteNextDNode(L);
    }
    free(L);//�ͷ�ͷ���
    L = NULL;//��ͷָ����Ϊ��
    
}

//˫����ı���
bool ThrouthDNode(DNode *p){
    //�������
    while (p != NULL)
    {
        /* code */
        p = p->next;
    }

    //ǰ�����
    while (p != NULL)
    {
        /* code */
        p = p->prior;
    }
    
    //ǰ���������ͷ���
    while (p->prior != NULL)
    {
        /* code */
        p = p->prior;
    }
    
    
}