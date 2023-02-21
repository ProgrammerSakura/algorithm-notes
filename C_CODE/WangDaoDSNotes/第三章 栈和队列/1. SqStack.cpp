#include<stdio.h>
#include<malloc.h>

#define MaxSize 10 //����ջ��Ԫ�ص�������

//˳��ջ�Ķ���
typedef struct {
    int data[MaxSize]; //�þ�̬���������ջ�е�Ԫ��
    int top;  //ջ��ָ��
}SqStack;

/*****��ʼ������*****/

//��ʼ��ջ
bool InitSqStack(SqStack &S) {
    S.top = -1; //topָ���ʾָ���ʱջ��Ԫ�ص�λ��
}



//�ж�ջ��
/*
    ˼·����ջ��ָ���Ƿ�ָ���ʼ��ʱ��ָ���λ�ã�
*/
bool StackEmpty(SqStack S) {
    if(S.top == -1)
        return true; //��
    return false; //�ǿ�
}

/***��ջ****/

//��Ԫ����ջ
/*
    ˼·��1.�ж�ջ�Ƿ����ˣ����򷵻ش���
         2.ջ��ָ���ȼ�һ
         3.����Ԫ����ջ 
*/
bool Push(SqStack &S, int x) {
    if(S.top = MaxSize - 1)
        return false; //ջ��
    S.top = S.top + 1;
    S.data[S.top] = x; //��Ԫ����ջ ����˳��ᵼ��ԭ����ջ��Ԫ�ر����ǡ�
    //�ȼ�д�� S.data[++S.top] = x;
    return true;
}

/***��ջ***/
/*
    ˼·��1. �ж��Ƿ�ջ�գ����򱨴�
         2. ��ջ��Ԫ���ȳ�ջ
         3. ջ��ָ���һ    
*/
bool Pop(SqStack &S, int &x) {
    if(S.top == -1)
        return false; //ջ��
    x = S.data[S.top]; //ջ��Ԫ�س�ջ��ʵ���ϻ������ڴ��У��߼��ϱ�ɾ����
    S.top = S.top - 1; //ջ��ָ���һ������˳������
    //�ȼ�д�� x = S.data[S.top--];
    return true; 
}

//��ȡջ��Ԫ��
/*
    ˼·��1. �ж�ջ�Ƿ�ǿ�
        2. ��ջ��Ԫ�ظ�ֵ������
*/
bool GetTop(SqStack S, int &x) {
    if(S.top == -1) 
        return false;
    x = S.data[S.top];
    return true;
}

