#include<stdio.h>
#include<malloc.h>

#define MaxSize 30;
typedef int ElemType;

//�ṹ��
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

//��ʼ��
void InitQueue(SqQueue &Q) {
    //��ʼʱ����ͷ��βָ��ָ��0��
    Q.rear = Q.front = 0;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//���
bool EnQueue(SqQueue &Q, ElemType x) {
    if(q.rear == MaxSize - 1) 
        return false;
    Q.data[Q.rear] = x;
    Q.rear++;
    return true;
}

//����
bool DeQueue(SqQueue &Q, ElemType x) {
    if(Q.rear == Q.front)
        return false;  //�ӿ�
    x = Q.data[Q.front];
    Q.front++;
    return false;
}