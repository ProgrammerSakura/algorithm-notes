#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
//�ṹ�����͵Ķ���
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *List;

List L;

//��ʼ������
List MakeEmpty()
{
    LNode * L = (List)malloc(sizeof(struct LNode));
    L = NULL;
    return L;
}

//���
int Length(List L){
    LNode *p = L;
    int len;
    while (p)
    {
        /* code */
        p = p->next;
        len++;
    }
    return len++;
}

//����Ų���
List Findkth(int k, List L){
    LNode *p = L;
    int i = 1;
    while (p != NULL && i < k) //�ҵ���k-1�����
    {
        /* code */
        p = p->next;
        i++;
    }
    if(i == k) //�ҵ���
        return p;
    else
        return NULL; //û�ҵ�
    
}

//��ֵ����
List Find(ElemType x, List L) {
    LNode *p = L;
    while (p != NULL && x != p->data)
    {
        /* code */
        p = p->next;
    }
    //�ҵ��˷���p,û�ҵ�����null
    return p;
}

//����
List Insert(ElemType x, int i, List &L) {
    LNode *p,*s;
    if(i == 1){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;
        //����Ľ����Ϊͷ���
        return s;
    }
    p = Findkth(i-1, L);
    if(!p){  //��i-1��㲻����
        printf("������");
        return NULL;
    }else{
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return L;
    }
}

//ɾ��
List Delete(int i, List &L){
    LNode *p, *s;
    //���ɾ������ͷ���
    if(i == 1){
        s = L;
        if(L){
            L = L->next; 
        } else {
            return NULL;
        }
        free(s);
        return L;
    }
    //���ҵ�i-1�����
    p = Findkth(i-1, L);
    if(!p || !(p->next)) {//�����i-1�������ߵ�i����㲻����
        printf("ɾ����λ�ô���\n");
        return NULL;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);
        return L;
    }
}

//�������Ԫ��
void Print(List L)
{
    LNode *p;
    int flag = 1;
    printf("��ǰ����Ϊ��\n");
    for(p = L; p; p = p->next){
        printf("%d\n", p->data);
        flag = 0;
    }
    if(flag)
        printf("NULL");
    printf("\n");
}

int main()
{
    L = MakeEmpty();//��ʼ��������
    Print(L);//��ӡ
    //����Ԫ��
    L = Insert(11, 1, L);
    L = Insert(12, 2, L);
    L = Insert(13, 3, L);
    L = Insert(14, 4, L);
    L = Insert(1, 5, L);
    //��ӡ������Ԫ��
    Print(L);
    printf("��ǰ������ĳ���Ϊ��%d\n", Length(L));
    printf("��ǰ�����еĵڶ�������ֵΪ��%d\n", Findkth(2, L)->data);
    printf("������Ҫ���ҵ�Ԫ��ֵ��");
    int elem;
    scanf("%d",&elem);
    if(Find(elem, L)){
        printf("��Ԫ���ڸ�������!\n");
    } else {
        printf("��Ԫ�ز��ڸ������У�\n");
    }
    //ɾ��
    printf("������Ҫɾ����Ԫ��λ�ã�");
    scanf("%d", &elem);
    if(Delete(elem, L))
        printf("ɾ���������Ϊ��\n");
    Print(L);
    return 0;


}