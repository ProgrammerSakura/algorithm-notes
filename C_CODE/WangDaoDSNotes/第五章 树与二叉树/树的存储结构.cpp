#include<stdio.h>
#include<malloc.h>

/*˫�ױ�ʾ��*/
/*
    ˼�룺
        ����˳��洢�ṹ��ÿ������д洢���ݺ�����˫���������е�λ��
*/
#define MAX_TREE_SIZE 100
typedef int ElemType;
//��㶨��
typedef struct{
    ElemType data; //����е�����
    int parent;   //˫��λ��
}PTNode;

//���Ľṹ
typedef struct{
    PTNode nodes[MAX_TREE_SIZE]; //�������
    int n; //�����
};

/*���ӱ�ʾ��*/

