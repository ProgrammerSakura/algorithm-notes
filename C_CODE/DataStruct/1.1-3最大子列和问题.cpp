#include<stdio.h>

//暴力解决
int MAxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j , k;
    for(i = 0; i < N; i++) { //i是子列的左侧位置
        ThisSum = 0;
        for(j = i; j < N; j++) { //j是子列的右侧位置
                ThisSum += A[j];
            if(ThisSum > MaxSum) //比较当前子列和的大小
                MaxSum = ThisSum; //大的话就更新最大值
        }
    }
    return MaxSum;
}
//6
//-2 11 -4 13 -5 -2
int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int MaxSum = 0;
    MaxSum = MAxSubseqSum(A, N);
    printf("%d\n", MaxSum);
}