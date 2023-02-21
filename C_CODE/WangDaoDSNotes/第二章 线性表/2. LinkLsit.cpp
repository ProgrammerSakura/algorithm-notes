#include<stdio.h>
#include<malloc.h>

//���Ķ���
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *LinkList;
//ע������ṹ��ĺ��壺
/*
    �ѽṹ��LNode��������ΪLNode,������һ��LinkListָ��ָ��������
    ʵ�������ǿ����� LNode *p�� LinkList p�ǵȼ۵ģ�ֻ����ǰ��ǿ������һ����㣬����ǿ������һ������
    ��㱾����û�����ֵġ���������һ��ָ�����ָ��ָ��ý�㣬Ȼ��Ըý�������ز���
    p->next ���Զ���p����һ������ַ��next��ָ����һ������ָ�룬ʵ����next����ľ�����һ������λ�ã�ʹ��p->next->data��ʾ��һ������������
*/

//����������ֳ�ʼ����ʽ

//��ʼ��һ����ͷ���ĵ�����
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //����һ��ͷ���
    if(L=NULL){
        return false; //�ڴ治�㣬����ʧ��
    }
    L->next = NULL; //����ͷ���ָ���
    return true;
}

// //����ͷ����ʼ��
bool InitList2(LinkList &L)
{
    L = NULL; //��������Ϊ��
    return true;
}


/******************************/
//����

//1. ��λ�����

//��ͷ���
bool ListInsert(LinkList &L, int i, int e)
{
    if(i < 1)
        return false;  //����λ�ò���ȷ
    
    //ע������ֱ�ӵ��ð�λ���Һ���
    //LNode *p = GetElem(L, i-1);
    LNode *p; //ָ��ǰ���
    int j=0; //��ǰpָ��Ľ��Ϊ�ڼ������
    p = L; //pָ��ͷ��㣬ͷ����ǵ�0�����
    while (p!=NULL && j<i-1)
    {
        /* code */
        p = p->next;
        j++;
    }

    //ע���ҵ�ָ���Ľ��p֮�����ֱ�ӵ��ú����������
    //InsertNextNode(p, e);
    if(p = NULL){
        return false; //��ʾi��ֵ���Ϸ�
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //�����s���ӵ�p֮��

    return true;//����ɹ�
    
}

//����ͷ���
/*
    ˼·��
    1. ���жϲ����λ���Ƿ���ȷ
    2. �Ե�һ�������е���������������뵽ͷ���֮��
    3. ����һ��ָ��ָ��ǰ��㣬������һ��������ʾ��ǰ���λ��
    4. ������������ѭ���ҵ���i-1�����
    5. �ж�p�Ƿ�Ϊ�գ���Ϊ�������
    6. ����һ���½�㣬���½��������ֵ���ٽ��½���nextָ��ָ��p��ָ��Ľ�㣬��pָ���½�㡣

*/
bool ListInsert2(LinkList &L, int i, int e)
{
    if(i<1)
        return false;
    if(i=1){
        //����һ���½��
        LNode *s = (LNode *)malloc(sizeof(LNode));
        //�Ѹý���������ֵ
        s->data = e;
        //���½���ָ����ָ��L��ָ��Ľ��
        s->next = L;
        //��ͷָ��Lָ������½��
        L = s;
        return true;
    }

    //��ָ��Pָ��ɨ�赽�Ľ��
    LNode *p;
    //pָ��Ľ��λ��
    int j = 1; 
    //ѭ���ҵ���i-1�����
    while (p!=NULL && j<i-1)
    {
        /* code */
        p=p->next;
        j++;
    }

    //i��ֵ������Χ
    if(p == NULL)
        return false;
    //����һ���½��
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;

}

//2.ָ�����ĺ�����
/*
    ˼·��
        1. ���жϲ���Ľ���Ƿ�Ϊ��
        2. ����һƬ�ռ䣬���ж��Ƿ�����ɹ�
        3. ���½��s���뵽p֮��
*/
bool InsertNextNode(LNode *p, int e)
{
    //�жϸĽ���Ƿ�Ϊ�� 
    /*
        ������Ҫ�ж�null��ԭ������Ϊ�������λ����Ļ�ֱ�ӵ��õ���GetElem()����������Ļ����ú������ܻ᷵��nullֵ������µ���ʧ�ܡ�
    */
    if(p == NULL)
        return false;
    //Ϊ�ý������ռ�
    LNode *s = (LNode *)malloc(sizeof(LNode));
    //�ж��Ƿ����ɹ�
    if(s == NULL)
        return false;
    //���ý���������ֵ
    s->data = e;
    s->next = p->next;
    p->next = s; //��p���ָ��s
    return true;
}

//3. ָ������ǰ�����
/*
    ˼·������������
        1. �ж�p����Ƿ�Ϊ��
        2. ����һƬ�ռ䣬���ж��Ƿ�����ɹ�
        3. ���½��sָ��p�����ָ��Ľ�㣬�ٽ�p���ָ��s���
        4. ��p�������ݸ��Ƶ�s�����
        5. �ٽ�p�������ݸ�ֵΪe
*/
bool InsertPriorNode(LNode *p, int e)
{
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;//����������
    p->data = e;
    return true;
}

/******************************/
//ɾ��
//��λ��ɾ��
/*
    ˼·��
        1. �жϲ����λ���Ƿ���ȷ
        2. �ҵ���i-1�����
        3. �ж�i��ֵ�Ƿ�Ϸ�
        4. �ж�ɾ���Ľ���Ƿ���������֮��
        5. ����һ���½��q��ָ��p����һ�����;
        6. ��qָ��Ľ���ֵ��ֵ��e
        7. �ٽ�pָ���µ�ɾ��֮��Ľ��
        8. �ͷŽ��ռ�
*/
bool ListDelete(LinkList &L, int i, int &e)
{
    if(i<1)
        return false;
    
    //ע������ֱ�ӵ��ð�λ���Һ���
    //LNode *p = GetElem(L,i-1);
    LNode *p;
    int j=0;
    p=L;
    while (p!=NULL&& j < i-1)
    {
        /* code */
        p = p->next;
        j++;
    }
    //�ж�iֵ�Ƿ�Ϸ�
    if(p==NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q;
    q = p->next;//����p����Ľ��λ�ã�����ɾ�����ͷ�
    e = q->data;
    p->next = q->next;//����p->next->next
    free(q);
    return true;
    
}

//ָ�����ɾ��
/*
    ˼·������̽���ֵ����������
        1. �жϸý���Ƿ�Ϊ��
        2. �¶���һ�����qָ����p�ĺ�̽��
        3. ��p�����̽��������򽻻�
        4. ��pָ��qָ��Ľ��
        5. �ͷź�̽��Ŀռ�;
*/
bool DeleteNode(LNode *p){
    if(p==NULL)
        return false;
    LNode *q = p->next; //��qָ��*�ĺ�̽��
    p->data = p->next->data;//�ͺ�̽�㽻��������
    p->next = q->next;//��*q�������С��Ͽ�"
    free(q);//�ͷź�̽��Ĵ洢�ռ�
    return true;
}

/******************************/
//������Ĳ���
//1. ��λ����
/*
    ˼·��
        1. ���жϲ��ҵ�λ���Ƿ���ȷ
        2. �ٶ���һ�����ָ��ͷ���
        3. ����һ��������ʾ��ǰpָ��Ľ��
        4. ѭ���ҵ���i�����
*/
LNode * GetElem(LinkList L, int i)
{
    if(i < 0)
        return NULL;
    LNode *p;
    p = L;
    int j = 0;
    while (p!=NULL && j<i)
    {   
        /* code */
        p = p->next;
        j++;
    }
    return p;

}

//2. ��ֵ����
/*
    ˼·��
        1. ����һ��ָ��ָ���һ�����
        2. �ӵ�һ����㿪ʼ����������Ϊe�Ľ��
        3. �ҵ��󷵻ؽ��ָ��
*/
LNode * LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p!=NULL && p->data != e)
    {
        /* code */
        p = p->next;
    }
    return p;
    

}

//3. ���ĳ���
/*
    ˼·��
        1. ����һ��������ͳ�Ʊ�
        2. ����һ��ָ�룬ָ��ͷ���
*/
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L; //ָ��ͷ���
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
        len++;
    }
    return len;
}

/******************************/
//������Ľ���
//1. β�巨����������
/*
    ˼·��
        1. ����һ����Ҫ�����Ԫ�����͵ı���
        2. ����ͷ���
        3. ��������ָ��ṹ���ָ�룬һ�����ڽ���ÿ�β���Ľ�㣬һ������ָ���β,����βָ��ָ��ͷ���
        4. ����Ҫ����Ľ���Ԫ��ֵ
        5. ѭ��������
        6. ����βָ����Ϊ��
*/
LinkList List_TailInsert(LinkList &L)
{
    int x; //�����Ԫ������
    L = (LNode *)malloc(sizeof(LNode)); //����ͷ���
    LNode *s, *r = L;
    scanf("%d",&x); //��������Ԫ��ֵ
    while (x != 9999)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;                                                    
        r->next = s;
        r = s;//rָ���µı�β���
        scanf("%d",&x);
    }
    //����βָ����Ϊ��
    r->next = NULL;
    return L;

}

//2. ͷ�巨����������
/*
    ˼·��
        1. ǰ��ĺ�β�巨һ��
        2. �����Ǵ�ͷ��������룬ʵ���Ͼ���ָ�����ĺ�����
*/
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    LNode *s;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //��ʼ������ʹ��ͷ���ָ���
    while (x != 9999)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        //��s���뵽ͷ���֮��
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}