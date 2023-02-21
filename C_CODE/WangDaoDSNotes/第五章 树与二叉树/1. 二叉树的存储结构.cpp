#include<stdio.h>
#include<malloc.h>

#define MaxSize 100
typedef int ElemType;

//顺序存储

struct TreeNode {
    ElemType value; //结点中的元素个数
    bool isEmpty;  //结点是否为空
};

TreeNode t[MaxSize];


//链式存储
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;