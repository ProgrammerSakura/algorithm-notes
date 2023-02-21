#include<stdio.h>
#include<malloc.h>

//链栈的实现
typedef struct LinKnode {
    ElemType data;
    struct LinKnode *next;
} *LinkStack;

typedef int ElemType;

//链栈的初始化
void InitStack(LinkStack &S) {
    S = (LinkStack)malloc(sizeof(LinkStack)); //创建一个带头结点的链栈
    S->next = NULL; //头结点设为空 
}

//销毁栈
/*
    思路：逐一释放全部结点的空间，定义两个结点，让pre，p指向两个相邻的结点，初始时pre指向头结点，p指向首结点。当p为空的时候释放结点pre，然后同步向后移动指向下一个结点。
    循环结束后，pre指向尾结点，再将其释放。
*/
void DestoryStack(LinkStack &S) {
    LinkStack pre = S, p = S->next; //pre指向头结点，p指向首结点
    while (p != NULL)  //扫描单链表L
    {
        /* code */
        free(pre);  //释放pre结点
        pre = p; //pre和p同步向后移动一个结点
        p = pre->next;
    }
    free(pre); //循环结束，p为NULL，pre指向尾结点释放它
}


//判断栈是否为空
bool EmptyStack(LinkStack &S) {
    if(S->next == NULL)
        return true;  //为空
    return false; //非空
}

//进栈
/*
    思路：在头结点后面插入即可
*/
void Push(LinkStack &S, ElemType x) {
    LinkStack p;  //新建一个结点p
    p->data = x;  //将p中存放元素x
    p->next = S->next; //将p结点插入到头结点之后
    S->next = p;
}

//出栈
/*
    思路：在表头删除头结点即可
*/
bool Pop(LinkStack &S, ElemType &x) {
    //判断栈是否非空
    if(S->next == NULL)
        return false;
  
    //删除首结点
    LinkStack p;
    p = S->next;
    S->next = p->next;
    //将栈首结点值赋值给x
    x = p->data; 
    free(p); //释放被删除结点的存储空间
    return true;
}

//取栈顶元素
/*
    思路：在栈非空的条件下获取首结点的值返回
*/
bool GetTop(LinkStack S,ElemType &x) {
   //判断栈是否为空
   if (S->next == NULL)
       return false; 

    x = S->next->data; //获取首结点的值
    return true;
    
}