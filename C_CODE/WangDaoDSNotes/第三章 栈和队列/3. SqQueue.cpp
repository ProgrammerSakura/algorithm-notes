#include<stdio.h>
#include<malloc.h>

#define MaxSize 30;
typedef int ElemType;

//结构体
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

//初始化
void InitQueue(SqQueue &Q) {
    //初始时，队头队尾指针指向0；
    Q.rear = Q.front = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q, ElemType x) {
    if(q.rear == MaxSize - 1) 
        return false;
    Q.data[Q.rear] = x;
    Q.rear++;
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType x) {
    if(Q.rear == Q.front)
        return false;  //队空
    x = Q.data[Q.front];
    Q.front++;
    return false;
}