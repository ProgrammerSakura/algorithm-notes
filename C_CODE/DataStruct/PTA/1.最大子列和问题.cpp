#include<stdio.h>

//�������
int MAxSubseqSum(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j , k;
    for(i = 0; i < N; i++) { //i�����е����λ��
        ThisSum = 0;
        for(j = i; j < N; j++) { //j�����е��Ҳ�λ��
                ThisSum += A[j];
            if(ThisSum > MaxSum) //�Ƚϵ�ǰ���к͵Ĵ�С
                MaxSum = ThisSum; //��Ļ��͸������ֵ
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