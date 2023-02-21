#include<stdio.h>
#include<malloc.h>

//��ջ��ʵ��
typedef struct LinKnode {
    ElemType data;
    struct LinKnode *next;
} *LinkStack;

typedef int ElemType;

//��ջ�ĳ�ʼ��
void InitStack(LinkStack &S) {
    S = (LinkStack)malloc(sizeof(LinkStack)); //����һ����ͷ������ջ
    S->next = NULL; //ͷ�����Ϊ�� 
}

//����ջ
/*
    ˼·����һ�ͷ�ȫ�����Ŀռ䣬����������㣬��pre��pָ���������ڵĽ�㣬��ʼʱpreָ��ͷ��㣬pָ���׽�㡣��pΪ�յ�ʱ���ͷŽ��pre��Ȼ��ͬ������ƶ�ָ����һ����㡣
    ѭ��������preָ��β��㣬�ٽ����ͷš�
*/
void DestoryStack(LinkStack &S) {
    LinkStack pre = S, p = S->next; //preָ��ͷ��㣬pָ���׽��
    while (p != NULL)  //ɨ�赥����L
    {
        /* code */
        free(pre);  //�ͷ�pre���
        pre = p; //pre��pͬ������ƶ�һ�����
        p = pre->next;
    }
    free(pre); //ѭ��������pΪNULL��preָ��β����ͷ���
}


//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(LinkStack &S) {
    if(S->next == NULL)
        return true;  //Ϊ��
    return false; //�ǿ�
}

//��ջ
/*
    ˼·����ͷ��������뼴��
*/
void Push(LinkStack &S, ElemType x) {
    LinkStack p;  //�½�һ�����p
    p->data = x;  //��p�д��Ԫ��x
    p->next = S->next; //��p�����뵽ͷ���֮��
    S->next = p;
}

//��ջ
/*
    ˼·���ڱ�ͷɾ��ͷ��㼴��
*/
bool Pop(LinkStack &S, ElemType &x) {
    //�ж�ջ�Ƿ�ǿ�
    if(S->next == NULL)
        return false;
  
    //ɾ���׽��
    LinkStack p;
    p = S->next;
    S->next = p->next;
    //��ջ�׽��ֵ��ֵ��x
    x = p->data; 
    free(p); //�ͷű�ɾ�����Ĵ洢�ռ�
    return true;
}

//ȡջ��Ԫ��
/*
    ˼·����ջ�ǿյ������»�ȡ�׽���ֵ����
*/
bool GetTop(LinkStack S,ElemType &x) {
   //�ж�ջ�Ƿ�Ϊ��
   if (S->next == NULL)
       return false; 

    x = S->next->data; //��ȡ�׽���ֵ
    return true;
    
}