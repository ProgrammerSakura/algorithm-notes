#include<stdio.h>
#include<malloc.h>

#define MaxSize 10 //静态链表的最大长度

//结构类型的定义
typedef struct {
    int data; //存储的数据元素
    int next; //下一个元素的数组下标
}SLinkList[MaxSize];

/******************************/
//等价
struct Node{
    int data;
    int next;
};
typedef struct Node SLinkList[MaxSize];

//两者在定义时的不同
void InitElement(){
    SLinkList a;
    struct Node a[MaxSize];
}

//初始化
/*
    把a[0]的next设为-1
    把其他结点的next设置为一个特殊的值来表示结点空闲，例如-2
*/

//查找
/*
    从头到尾依次进行遍历
*/

//插入
/*
    1. 找到一个为空的结点，存入数据元素
    2. 从头结点触发找到对应位序为i-1的结点
    3. 修改新结点的next
    4. 修改i-1号结点的next
*/

//删除
/*
    ①从头结点出发找到前驱结点
    ②修改前驱结点的游标
    ③被删除结点next设为-2
*/