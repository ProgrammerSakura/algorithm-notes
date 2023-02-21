#include<stdio.h>
#include<malloc.h>

//结点的定义
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *LinkList;
//注：这个结构体的含义：
/*
    把结构体LNode重新命名为LNode,并定义一个LinkList指针指向这个结点
    实际上我们看到的 LNode *p与 LinkList p是等价的，只不过前者强调的是一个结点，后者强调的是一个链表
    结点本来是没有名字的。可以设置一个指向结点的指针指向该结点，然后对该结点进行相关操作
    p->next 可以读作p的下一个结点地址，next是指向下一个结点的指针，实际上next保存的就是下一个结点的位置，使用p->next->data表示下一个结点的数据域
*/

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
    
    //注：可以直接调用按位查找函数
    //LNode *p = GetElem(L, i-1);
    LNode *p; //指向当前结点
    int j=0; //当前p指向的结点为第几个结点
    p = L; //p指向头结点，头结点是第0个结点
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
    /*
        这里需要判断null的原因是因为，如果按位插入的话直接调用的是GetElem()，这个函数的话，该函数可能会返回null值，最后导致调用失败。
    */
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
    
    //注：可以直接调用按位查找函数
    //LNode *p = GetElem(L,i-1);
    LNode *p;
    int j=0;
    p=L;
    while (p!=NULL&& j < i-1)
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
    q = p->next;//保存p结点后的结点位置，便于删除后释放
    e = q->data;
    p->next = q->next;//或者p->next->next
    free(q);
    return true;
    
}

//指定结点删除
/*
    思路：将后继结点的值赋予其自身
        1. 判断该结点是否为空
        2. 新定义一个结点q指向结点p的后继结点
        3. 将p与其后继结点的数据域交换
        4. 将p指向q指向的结点
        5. 释放后继结点的空间;
*/
bool DeleteNode(LNode *p){
    if(p==NULL)
        return false;
    LNode *q = p->next; //令q指向*的后继结点
    p->data = p->next->data;//和后继结点交换数据域
    p->next = q->next;//将*q结点从链中“断开"
    free(q);//释放后继结点的存储空间
    return true;
}

/******************************/
//单链表的查找
//1. 按位查找
/*
    思路：
        1. 先判断查找的位置是否正确
        2. 再定义一个结点指向头结点
        3. 定义一个变量表示当前p指向的结点
        4. 循环找到第i个结点
*/
LNode * GetElem(LinkList L, int i)
{
    if(i < 0)
        return NULL;
    LNode *p;
    p = L;
    int j = 0;
    while (p!=NULL && j<i)
    {   
        /* code */
        p = p->next;
        j++;
    }
    return p;

}

//2. 按值查找
/*
    思路：
        1. 定义一个指针指向第一个结点
        2. 从第一个结点开始查找数据域为e的结点
        3. 找到后返回结点指针
*/
LNode * LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p!=NULL && p->data != e)
    {
        /* code */
        p = p->next;
    }
    return p;
    

}

//3. 求表的长度
/*
    思路：
        1. 定义一个变量来统计表长
        2. 定义一个指针，指向头结点
*/
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L; //指向头结点
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
        len++;
    }
    return len;
}

/******************************/
//单链表的建立
//1. 尾插法建立单链表
/*
    思路：
        1. 定义一个需要插入的元素类型的变量
        2. 建立头结点
        3. 定义两个指向结构体的指针，一个用于建立每次插入的结点，一个用于指向表尾,将表尾指针指向头结点
        4. 输入要插入的结点的元素值
        5. 循环插入结点
        6. 将表尾指针置为空
*/
LinkList List_TailInsert(LinkList &L)
{
    int x; //插入的元素类型
    L = (LNode *)malloc(sizeof(LNode)); //建立头结点
    LNode *s, *r = L;
    scanf("%d",&x); //输入插入的元素值
    while (x != 9999)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;                                                    
        r->next = s;
        r = s;//r指向新的表尾结点
        scanf("%d",&x);
    }
    //将表尾指针置为空
    r->next = NULL;
    return L;

}

//2. 头插法建立单链表
/*
    思路：
        1. 前面的和尾插法一样
        2. 插入是从头结点后面插入，实际上就是指定结点的后插操作
*/
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    LNode *s;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //初始化链表，使得头结点指向空
    while (x != 9999)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        //将s插入到头结点之后
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}