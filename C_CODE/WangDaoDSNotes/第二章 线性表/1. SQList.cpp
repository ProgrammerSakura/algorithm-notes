#include<stdio.h>
#include<malloc.h>

/*˳���Ľ���*/
//��̬����
#define MaxSize 10 //������󳤶�
typedef struct{
    int data[MaxSize]; //ʹ�þ�̬����������
    int length; //˳���ǰ�ĳ���
}Sqlist;

/* ����ע�ͣ�ctrl+/ ����ע�ͣ�alt+shit+A */

/* 
//��̬����
typedef struct{
    int *data; //ָ��̬���������ָ��
    int MaxSize; //˳�����������
    int lenth; //˳���ĵ�ǰ����
}Sqlist;
 */

//���Ա�ĳ�ʼ�� O(1)
void InitList(Sqlist *&L)  //����һ������Ϊָ��Sqlist��ָ�룬��������ָ����
{
    L = (Sqlist *)malloc(sizeof(Sqlist));//���������Ա�Ŀռ�
    L->length = 0;                       //���L�ǽṹ��Ļ�ʹ��L.length,����L��ָ������ʹ��L->length
}


//�������Ա�
void DestroyList(Sqlist *&L)
{
    free(L); //����free()�����ͷ�˳���ռ�
}

//�ж����Ա��Ƿ�Ϊ�ձ� O(1)
bool ListEmpty(Sqlist *L)
{
    return(L->length == 0);
}

//�����Ա�ĳ���
int ListLength(Sqlist *L)
{
    return (L->length);

}

//������Ա� O(n)
int DispList(Sqlist *L)
{
    //�ӵ�0��Ԫ�ؿ�ʼ�������
    for(int i = 0; i < L->length; i++)
    {
        printf("%d", L->data[i]);
    }
}

// ��������Ԫ�� O(n)
bool ListInsert(Sqlist *&L, int i, int e)
{
    //�ж�i�ķ�Χ�Ƿ���Ч
    if(i<1 || i>L->length+1) //1<=i<=L->length+1��λ��
        return false;
    
    //�����ǰ�洢�ռ�����������ʧ��
    if(L->length >= MaxSize)
        return false;
    
    //
    for(int j=L->length; j>=i;j--)
    {
        L->data[j] = L->data[j-1]; //����i��Ԫ�ؼ�֮���Ԫ�غ��� j��Ӧ���������е�j-1λ��
    }
    L->data[i-1] = e; //λ��i��Ӧ��ʵ�����������i-1λ��
    L->length++;  //���Ա��ȼ�1;
    return true;
}

//ɾ������Ԫ�� O(n)
bool ListDelete(Sqlist *&L, int i, int &e)
{
    //�жϵķ�Χ�Ƿ���Ч
    if(i<1 || i>L->length)  //1<=i<=L->length+1
        return false;
    e = L->data[i];   //��ɾ����Ԫ�ص�ֵ��ֵ��e
    for(int j=i; j<L->length; j++)
    {
        L->data[j-1] = L->data[j]; //����i��λ�õ�Ԫ��ǰ��
    }
    
}

//��ֵ����(˳�����) O(n)
/* ���ҵ�һ��Ԫ�ص���e��Ԫ�أ����ҷ�����λ�� */
int LocateElem(Sqlist *L, int e)
{
    for(int i=0; i<L->length; i++)
    {
        if(L->data[i]=e)
            return i+1;  //�±�Ϊi��Ԫ��ֵ��Ӧ��λ��Ϊi+1;
    }
    return 0; //����ʧ��
}

