#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
//结构体类型的定义
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *List;

List L;

//初始化链表
List MakeEmpty()
{
    LNode * L = (List)malloc(sizeof(struct LNode));
    L = NULL;
    return L;
}

//求表长
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

//按序号查找
List Findkth(int k, List L){
    LNode *p = L;
    int i = 1;
    while (p != NULL && i < k) //找到第k-1个结点
    {
        /* code */
        p = p->next;
        i++;
    }
    if(i == k) //找到了
        return p;
    else
        return NULL; //没找到
    
}

//按值查找
List Find(ElemType x, List L) {
    LNode *p = L;
    while (p != NULL && x != p->data)
    {
        /* code */
        p = p->next;
    }
    //找到了返回p,没找到返回null
    return p;
}

//插入
List Insert(ElemType x, int i, List &L) {
    LNode *p,*s;
    if(i == 1){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;
        //插入的结点作为头结点
        return s;
    }
    p = Findkth(i-1, L);
    if(!p){  //第i-1结点不存在
        printf("结点错误！");
        return NULL;
    }else{
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return L;
    }
}

//删除
List Delete(int i, List &L){
    LNode *p, *s;
    //如果删除的是头结点
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
    //查找第i-1个结点
    p = Findkth(i-1, L);
    if(!p || !(p->next)) {//如果第i-1个结点或者第i个结点不存在
        printf("删除的位置错误！\n");
        return NULL;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);
        return L;
    }
}

//输出链表元素
void Print(List L)
{
    LNode *p;
    int flag = 1;
    printf("当前链表为：\n");
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
    L = MakeEmpty();//初始化单链表
    Print(L);//打印
    //插入元素
    L = Insert(11, 1, L);
    L = Insert(12, 2, L);
    L = Insert(13, 3, L);
    L = Insert(14, 4, L);
    L = Insert(1, 5, L);
    //打印插入后的元素
    Print(L);
    printf("当前单链表的长度为：%d\n", Length(L));
    printf("当前链表中的第二个结点的值为：%d\n", Findkth(2, L)->data);
    printf("请输入要查找的元素值：");
    int elem;
    scanf("%d",&elem);
    if(Find(elem, L)){
        printf("该元素在该链表中!\n");
    } else {
        printf("该元素不在该链表中！\n");
    }
    //删除
    printf("请输入要删除的元素位置：");
    scanf("%d", &elem);
    if(Delete(elem, L))
        printf("删除后的链表为：\n");
    Print(L);
    return 0;


}