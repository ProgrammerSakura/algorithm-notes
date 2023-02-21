#include<stdio.h>
#include<malloc.h>

/*双亲表示法*/
/*
    思想：
        采用顺序存储结构，每个结点中存储数据和他的双亲在数组中的位置
*/
#define MAX_TREE_SIZE 100
typedef int ElemType;
//结点定义
typedef struct{
    ElemType data; //结点中的数据
    int parent;   //双亲位置
}PTNode;

//树的结构
typedef struct{
    PTNode nodes[MAX_TREE_SIZE]; //结点数组
    int n; //结点数
};

/*孩子表示法*/

