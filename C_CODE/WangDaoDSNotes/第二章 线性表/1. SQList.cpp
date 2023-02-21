#include<stdio.h>
#include<malloc.h>

/*顺序表的建立*/
//静态分配
#define MaxSize 10 //定义最大长度
typedef struct{
    int data[MaxSize]; //使用静态数组存放数据
    int length; //顺序表当前的长度
}Sqlist;

/* 单行注释：ctrl+/ 多行注释：alt+shit+A */

/* 
//动态分配
typedef struct{
    int *data; //指向动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int lenth; //顺序表的当前长度
}Sqlist;
 */

//线性表的初始化 O(1)
void InitList(Sqlist *&L)  //传入一个参数为指向Sqlist的指针，并且引用指向它
{
    L = (Sqlist *)malloc(sizeof(Sqlist));//分配存放线性表的空间
    L->length = 0;                       //如果L是结构体的话使用L.length,这里L是指针所以使用L->length
}


//销毁线性表
void DestroyList(Sqlist *&L)
{
    free(L); //调用free()函数释放顺序表空间
}

//判断线性表是否为空表 O(1)
bool ListEmpty(Sqlist *L)
{
    return(L->length == 0);
}

//求线性表的长度
int ListLength(Sqlist *L)
{
    return (L->length);

}

//输出线性表 O(n)
int DispList(Sqlist *L)
{
    //从第0个元素开始遍历输出
    for(int i = 0; i < L->length; i++)
    {
        printf("%d", L->data[i]);
    }
}

// 插入数据元素 O(n)
bool ListInsert(Sqlist *&L, int i, int e)
{
    //判断i的范围是否有效
    if(i<1 || i>L->length+1) //1<=i<=L->length+1，位序
        return false;
    
    //如果当前存储空间已满，插入失败
    if(L->length >= MaxSize)
        return false;
    
    //
    for(int j=L->length; j>=i;j--)
    {
        L->data[j] = L->data[j-1]; //将第i个元素及之后的元素后移 j对应的是数组中的j-1位置
    }
    L->data[i-1] = e; //位置i对应的实际上是数组的i-1位置
    L->length++;  //线性表长度加1;
    return true;
}

//删除数据元素 O(n)
bool ListDelete(Sqlist *&L, int i, int &e)
{
    //判断的范围是否有效
    if(i<1 || i>L->length)  //1<=i<=L->length+1
        return false;
    e = L->data[i];   //将删除的元素的值赋值给e
    for(int j=i; j<L->length; j++)
    {
        L->data[j-1] = L->data[j]; //将第i个位置的元素前移
    }
    
}

//按值查找(顺序查找) O(n)
/* 查找第一个元素等于e的元素，并且返回其位序 */
int LocateElem(Sqlist *L, int e)
{
    for(int i=0; i<L->length; i++)
    {
        if(L->data[i]=e)
            return i+1;  //下标为i的元素值对应的位序为i+1;
    }
    return 0; //查找失败
}

