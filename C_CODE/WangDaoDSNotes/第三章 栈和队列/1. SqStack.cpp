#include<stdio.h>
#include<malloc.h>

#define MaxSize 10 //定义栈中元素的最大个数

//顺序栈的定义
typedef struct {
    int data[MaxSize]; //用静态数组来存放栈中的元素
    int top;  //栈顶指针
}SqStack;

/*****初始化操作*****/

//初始化栈
bool InitSqStack(SqStack &S) {
    S.top = -1; //top指针表示指向此时栈顶元素的位置
}



//判断栈空
/*
    思路：看栈顶指针是否指向初始化时候指向的位置；
*/
bool StackEmpty(SqStack S) {
    if(S.top == -1)
        return true; //空
    return false; //非空
}

/***进栈****/

//新元素入栈
/*
    思路：1.判断栈是否满了，否则返回错误
         2.栈顶指针先加一
         3.将新元素入栈 
*/
bool Push(SqStack &S, int x) {
    if(S.top = MaxSize - 1)
        return false; //栈满
    S.top = S.top + 1;
    S.data[S.top] = x; //新元素入栈 交换顺序会导致原来的栈顶元素被覆盖、
    //等价写法 S.data[++S.top] = x;
    return true;
}

/***出栈***/
/*
    思路：1. 判断是否栈空，否则报错
         2. 将栈顶元素先出栈
         3. 栈顶指针减一    
*/
bool Pop(SqStack &S, int &x) {
    if(S.top == -1)
        return false; //栈空
    x = S.data[S.top]; //栈顶元素出栈，实际上还存在内存中，逻辑上被删除了
    S.top = S.top - 1; //栈顶指针减一，交换顺序会出错
    //等价写法 x = S.data[S.top--];
    return true; 
}

//读取栈顶元素
/*
    思路：1. 判断栈是否非空
        2. 将栈顶元素赋值给变量
*/
bool GetTop(SqStack S, int &x) {
    if(S.top == -1) 
        return false;
    x = S.data[S.top];
    return true;
}

