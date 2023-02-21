#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

//��ʽ�洢
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//���ʽ��
void visit(BiTree T);

//�������
/*
    ˼·��
        1. ���жϸ����Ƿ�Ϊ��
        2. �ȷ��ʸ����
        3. �����������
        4. ��������ҽ��
*/
void PreOrder(BiTree T) {
    if (T != NULL)
    {
        visit(T); //���ʸ����
        PreOrder(T->lchild);  //��������
        PreOrder(T->rchild);  //�����ҽ��
    }
    
}

//�������
/*
    ˼·��
        1. ���ж��Ƿ�Ϊ��
        2. �����������
        3. ���ʸ����
        4. ��������ҽ��
*/
void InOrder(BiTree T) {
    if (T != NULL)
    {
        /* code */
        InOrder(T->lchild); //����������
        visit(T); //���ʸ����
        InOrder(T->rchild); //����������
    }
}

//�������
/*
    ˼·��
        1. ���ж��Ƿ�Ϊ��
        2. ���������
        3. ��������ҽ��
        4. ���ʸ����
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





//������Ӧ��
/*���������*/
/*
    ˼·��
        1. �жϸ����Ƿ�Ϊ��
        2. �ݹ���øú�������������������������������
        3. �ݹ���øú�������������������������������
        4. �Ƚ�������������ȴ�С�����ĳ�������һ���Ǹ��������
*/
int TreeDepth(BiTree T) {
    if (T == NULL)
        return 0;
    else {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        return r > l ? : r + 1 ; l + 1;  //������� = �������������ȼ�һ��
    }
    
}