#include<stdio.h>
#include<malloc.h>

#define MaxSize 100
typedef int ElemType;

//˳��洢

struct TreeNode {
    ElemType value; //����е�Ԫ�ظ���
    bool isEmpty;  //����Ƿ�Ϊ��
};

TreeNode t[MaxSize];


//��ʽ�洢
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;