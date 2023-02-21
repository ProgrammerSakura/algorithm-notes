# ���������

```c
#include<stdio.h>
#include<malloc.h>

//���Ķ���
typedef struct
{
    int data;
    LNode *next;
}LNode, *LinkList;

//����������ֳ�ʼ����ʽ

//��ʼ��һ����ͷ���ĵ�����
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //����һ��ͷ���
    if(L=NULL){
        return false; //�ڴ治�㣬����ʧ��
    }
    L->next = NULL; //����ͷ���ָ���
    return true;
}

// //����ͷ����ʼ��
bool InitList2(LinkList &L)
{
    L = NULL; //��������Ϊ��
    return true;
}


/******************************/
//����

//1. ��λ�����

//��ͷ���
bool ListInsert(LinkList &L, int i, int e)
{
    if(i < 1)
        return false;  //����λ�ò���ȷ
    LNode *p; //ָ��ǰ���
    int j=0; //��ǰpָ��Ľ��Ϊ�ڼ������
    p = L; //Lָ��ͷ��㣬ͷ����ǵ�0�����
    while (p!=NULL && j<i-1)
    {
        /* code */
        p = p->next;
        j++;
    }
    //ע���ҵ�ָ���Ľ��p֮�����ֱ�ӵ��ú����������
    //InsertNextNode(p, e);
    if(p = NULL){
        return false; //��ʾi��ֵ���Ϸ�
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //�����s���ӵ�p֮��
    return true;//����ɹ�

}

//����ͷ���
/*
    ˼·��
    1. ���жϲ����λ���Ƿ���ȷ
    2. �Ե�һ�������е���������������뵽ͷ���֮��
    3. ����һ��ָ��ָ��ǰ��㣬������һ��������ʾ��ǰ���λ��
    4. ������������ѭ���ҵ���i-1�����
    5. �ж�p�Ƿ�Ϊ�գ���Ϊ�������
    6. ����һ���½�㣬���½��������ֵ���ٽ��½���nextָ��ָ��p��ָ��Ľ�㣬��pָ���½�㡣

*/
bool ListInsert2(LinkList &L, int i, int e)
{
    if(i<1)
        return false;
    if(i=1){
        //����һ���½��
        LNode *s = (LNode *)malloc(sizeof(LNode));
        //�Ѹý���������ֵ
        s->data = e;
        //���½���ָ����ָ��L��ָ��Ľ��
        s->next = L;
        //��ͷָ��Lָ������½��
        L = s;
        return true;
    }

    //��ָ��Pָ��ɨ�赽�Ľ��
    LNode *p;
    //pָ��Ľ��λ��
    int j = 1; 
    //ѭ���ҵ���i-1�����
    while (p!=NULL && j<i-1)
    {
        /* code */
        p=p->next;
        j++;
    }

    //i��ֵ������Χ
    if(p == NULL)
        return false;
    //����һ���½��
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;

}

//2.ָ�����ĺ�����
/*
    ˼·��
        1. ���жϲ���Ľ���Ƿ�Ϊ��
        2. ����һƬ�ռ䣬���ж��Ƿ�����ɹ�
        3. ���½��s���뵽p֮��
*/
bool InsertNextNode(LNode *p, int e)
{
    //�жϸĽ���Ƿ�Ϊ��
    if(p == NULL)
        return false;
    //Ϊ�ý������ռ�
    LNode *s = (LNode *)malloc(sizeof(LNode));
    //�ж��Ƿ����ɹ�
    if(s == NULL)
        return false;
    //���ý���������ֵ
    s->data = e;
    s->next = p->next;
    p->next = s; //��p���ָ��s
    return true;
}

//3. ָ������ǰ�����
/*
    ˼·������������
        1. �ж�p����Ƿ�Ϊ��
        2. ����һƬ�ռ䣬���ж��Ƿ�����ɹ�
        3. ���½��sָ��p�����ָ��Ľ�㣬�ٽ�p���ָ��s���
        4. ��p�������ݸ��Ƶ�s�����
        5. �ٽ�p�������ݸ�ֵΪe
*/
bool InsertPriorNode(LNode *p, int e)
{
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;//����������
    p->data = e;
    return true;
}

/******************************/
//ɾ��
//��λ��ɾ��
/*
    ˼·��
        1. �жϲ����λ���Ƿ���ȷ
        2. �ҵ���i-1�����
        3. �ж�i��ֵ�Ƿ�Ϸ�
        4. �ж�ɾ���Ľ���Ƿ���������֮��
        5. ����һ���½��q��ָ��p����һ�����;
        6. ��qָ��Ľ���ֵ��ֵ��e
        7. �ٽ�pָ���µ�ɾ��֮��Ľ��
        8. �ͷŽ��ռ�
*/
bool ListDelete(LinkList &L, int i, int &e)
{
    if(i<1)
        return false;
    LNode *p;
    int j=0;
    p=L;
    while (p!=NULL&& j < j-1)
    {
        /* code */
        p = p->next;
        j++;
    }
    //�ж�iֵ�Ƿ�Ϸ�
    if(p==NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q;
    q = p->next;
    e = q->data;
    p->next = q->next;//����p->next->next
    free(q);
    return true;

}

//ָ�����ɾ��
```
