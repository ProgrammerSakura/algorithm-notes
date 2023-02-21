# 单链表代码

```c
#include<stdio.h>
#include<malloc.h>

//结点的定义
typedef struct
{
    int data;
    LNode *next;
}LNode, *LinkList;

//单链表的两种初始化方式

//初始化一个带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if(L=NULL){
        return false; //内存不足，分配失败
    }
    L->next = NULL; //设置头结点指向空
    return true;
}

// //不带头结点初始化
bool InitList2(LinkList &L)
{
    L = NULL; //将表设置为空
    return true;
}


/******************************/
//插入

//1. 按位序插入

//带头结点
bool ListInsert(LinkList &L, int i, int e)
{
    if(i < 1)
        return false;  //插入位置不正确
    LNode *p; //指向当前结点
    int j=0; //当前p指向的结点为第几个结点
    p = L; //L指向头结点，头结点是第0个结点
    while (p!=NULL && j<i-1)
    {
        /* code */
        p = p->next;
        j++;
    }
    //注：找到指定的结点p之后可以直接调用后插操作来完成
    //InsertNextNode(p, e);
    if(p = NULL){
        return false; //表示i的值不合法
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //将结点s连接到p之后
    return true;//插入成功

}

//不带头结点
/*
    思路：
    1. 先判断插入的位序是否正确
    2. 对第一个结点进行单独操作，将其插入到头结点之后
    3. 设置一个指针指向当前结点，并设置一个变量表示当前结点位置
    4. 根据上述变量循环找到第i-1个结点
    5. 判断p是否为空，若为空则错误。
    6. 申请一个新结点，将新结点数据域赋值，再将新结点的next指针指向p所指向的结点，将p指向新结点。

*/
bool ListInsert2(LinkList &L, int i, int e)
{
    if(i<1)
        return false;
    if(i=1){
        //申请一个新结点
        LNode *s = (LNode *)malloc(sizeof(LNode));
        //把该结点的数据域赋值
        s->data = e;
        //将新结点的指针域指向L所指向的结点
        s->next = L;
        //将头指针L指向这个新结点
        L = s;
        return true;
    }

    //将指针P指向扫描到的结点
    LNode *p;
    //p指向的结点位置
    int j = 1; 
    //循环找到第i-1个结点
    while (p!=NULL && j<i-1)
    {
        /* code */
        p=p->next;
        j++;
    }

    //i的值超出范围
    if(p == NULL)
        return false;
    //创建一个新结点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;

}

//2.指定结点的后插操作
/*
    思路：
        1. 先判断插入的结点是否为空
        2. 申请一片空间，并判断是否申请成功
        3. 将新结点s插入到p之后
*/
bool InsertNextNode(LNode *p, int e)
{
    //判断改结点是否为空
    if(p == NULL)
        return false;
    //为该结点申请空间
    LNode *s = (LNode *)malloc(sizeof(LNode));
    //判断是否分配成功
    if(s == NULL)
        return false;
    //将该结点的数据域赋值
    s->data = e;
    s->next = p->next;
    p->next = s; //将p结点指向s
    return true;
}

//3. 指定结点的前插操作
/*
    思路：交换数据域
        1. 判断p结点是否为空
        2. 申请一片空间，并判断是否申请成功
        3. 将新结点s指向p结点所指向的结点，再将p结点指向s结点
        4. 将p结点的数据复制到s结点中
        5. 再将p结点的数据赋值为e
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
    s->data = p->data;//交换数据域
    p->data = e;
    return true;
}

/******************************/
//删除
//按位序删除
/*
    思路：
        1. 判断插入的位序是否正确
        2. 找到第i-1个结点
        3. 判断i的值是否合法
        4. 判断删除的结点是否在这个结点之内
        5. 定义一个新结点q，指向p的下一个结点;
        6. 将q指向的结点的值赋值给e
        7. 再将p指向新的删除之后的结点
        8. 释放结点空间
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
    //判断i值是否合法
    if(p==NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q;
    q = p->next;
    e = q->data;
    p->next = q->next;//或者p->next->next
    free(q);
    return true;

}

//指定结点删除
```
