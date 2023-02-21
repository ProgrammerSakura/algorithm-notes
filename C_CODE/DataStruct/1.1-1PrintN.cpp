#include<stdio.h>

//循环实现
void PrintN_1(int N)
{
    int i;
    for(i=1; i<=N; i++)
    {
        printf("%d\t",i);
    }
}

//递归实现
void PrintN_2(int N)
{
    if(N)
    {
        PrintN_2(N-1);
        printf("%d\t",N);
        
    }
}

//主函数
int main()
{
    //循环调用
    int N;
    printf("请输入打印的数: ");
    scanf("%d",&N);
    printf("\n循环输出结果\n");
    PrintN_1(N);
    
    //递归调用
    printf("\n递归输出结果：\n");
    PrintN_2(N);
    return 0;
}
