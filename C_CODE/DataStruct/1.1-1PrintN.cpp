#include<stdio.h>

//ѭ��ʵ��
void PrintN_1(int N)
{
    int i;
    for(i=1; i<=N; i++)
    {
        printf("%d\t",i);
    }
}

//�ݹ�ʵ��
void PrintN_2(int N)
{
    if(N)
    {
        PrintN_2(N-1);
        printf("%d\t",N);
        
    }
}

//������
int main()
{
    //ѭ������
    int N;
    printf("�������ӡ����: ");
    scanf("%d",&N);
    printf("\nѭ��������\n");
    PrintN_1(N);
    
    //�ݹ����
    printf("\n�ݹ���������\n");
    PrintN_2(N);
    return 0;
}
