#include<stdio.h>
#include<malloc.h>

#define MaxSize 10 //��̬�������󳤶�

//�ṹ���͵Ķ���
typedef struct {
    int data; //�洢������Ԫ��
    int next; //��һ��Ԫ�ص������±�
}SLinkList[MaxSize];

/******************************/
//�ȼ�
struct Node{
    int data;
    int next;
};
typedef struct Node SLinkList[MaxSize];

//�����ڶ���ʱ�Ĳ�ͬ
void InitElement(){
    SLinkList a;
    struct Node a[MaxSize];
}

//��ʼ��
/*
    ��a[0]��next��Ϊ-1
    ����������next����Ϊһ�������ֵ����ʾ�����У�����-2
*/

//����
/*
    ��ͷ��β���ν��б���
*/

//����
/*
    1. �ҵ�һ��Ϊ�յĽ�㣬��������Ԫ��
    2. ��ͷ��㴥���ҵ���Ӧλ��Ϊi-1�Ľ��
    3. �޸��½���next
    4. �޸�i-1�Ž���next
*/

//ɾ��
/*
    �ٴ�ͷ�������ҵ�ǰ�����
    ���޸�ǰ�������α�
    �۱�ɾ�����next��Ϊ-2
*/