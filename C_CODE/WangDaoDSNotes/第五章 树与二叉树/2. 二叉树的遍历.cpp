#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

//链式存储
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//访问结点
void visit(BiTree T);

//先序遍历
/*
    思路：
        1. 先判断该树是否为空
        2. 先访问根结点
        3. 先序遍历左结点
        4. 先序遍历右结点
*/
void PreOrder(BiTree T) {
    if (T != NULL)
    {
        visit(T); //访问根结点
        PreOrder(T->lchild);  //访问左结点
        PreOrder(T->rchild);  //访问右结点
    }
    
}

//中序遍历
/*
    思路：
        1. 先判断是否为空
        2. 中序遍历左结点
        3. 访问根结点
        4. 中序遍历右结点
*/
void InOrder(BiTree T) {
    if (T != NULL)
    {
        /* code */
        InOrder(T->lchild); //遍历左子树
        visit(T); //访问根结点
        InOrder(T->rchild); //遍历右子树
    }
}

//后序遍历
/*
    思路：
        1. 先判断是否为空
        2. 后遍历左结点
        3. 后序遍历右结点
        4. 访问根结点
*/
void PostOrder(BiTree T) {
    if (T != NULL)
    {
        /* code */
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T); 
    }
}





//遍历的应用
/*求树的深度*/
/*
    思路：
        1. 判断该树是否为空
        2. 递归调用该函数，遍历左子树，求出左子树的深度
        3. 递归调用该函数，遍历右子树，求出右子树的深度
        4. 比较左右子树的深度大小，如果某个大，则加一就是该树的深度
*/
int TreeDepth(BiTree T) {
    if (T == NULL)
        return 0;
    else {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        return r > l ? : r + 1 ; l + 1;  //树的深度 = 左右子树最大深度加一。
    }
    
}