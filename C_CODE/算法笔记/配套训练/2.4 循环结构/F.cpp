#include<stdio.h>

//�򵥷���
/* 
    �㷨˼�룺
        ���۲죬����Ľ��Ϊһ���������еľ��󣬵�һ��Ϊ1*1��1*2�������ڶ���Ϊ2*1��2*2������ͬ��������һ�����ʿ�������
 */
int main()
{
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 5; j++){
            printf("%3d", i * j);
            if(j == 5)
                printf("\n");
        }
    }
}



/* ���ӷ���
int main() {
    int num = 1;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 1;
        if(i == 1) 
            printf("\n");
    }
    num = 2;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 2;
        if(i == 1) 
            printf("\n");
    }
    num = 3;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 3;
        if(i == 1) 
            printf("\n");
    }
    num = 4;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 4;
        if(i == 1) 
            printf("\n");
    }
    return 0;
} */