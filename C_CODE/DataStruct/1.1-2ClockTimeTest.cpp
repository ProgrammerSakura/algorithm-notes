#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAXN 101 //����ʽ���������������ʽ����+1 note:̫��ûдC�������Ǻ��ǲ��ܼӱ�������....
#define MAXK 1e7 //���⺯������ظ����ô���


clock_t start,stop;
double duration;

/**
    clock��������׽�ӳ���ʼ���е�clock����������ʱ���ķѵ�ʱ�䡣���ʱ�䵥λ��clock tick������ʱ�Ӵ�㡱
    ����CLKTCK������ʱ��ÿ�����ߵ�ʱ�Ӵ������
*/

//��������
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

//������
int main()
{
    int i;
    double a[MAXN]; //�洢����ʽϵ��

    for ( i = 0; i < MAXN; i++)
    {
        /* code */
        if(i = 0){
            a[i] = 1;
        } else
        {
            /* code */
            a[i] = 1.0 / (double)i;
        }
        
        
    }

    start = clock();   //��ʼ��ʱ
    for(i=0; i<MAXK; i++)
    {
        f1(MAXN-1, a, 1.1);
    }
    stop = clock(); //ֹͣ��ʱ
    duration = ((double)(stop-start))/CLK_TCK/MAXK; //���㻨�ѵ�ʱ��
    printf("ticks1 = %f\n", (double)(stop-start)); //���ʱ�Ӵ��
    printf("duration = %6.2e\n", duration); //�������ʱ��

    start = clock();   //��ʼ��ʱ
    for(i=0; i<MAXK; i++)
    {
        f2(MAXN-1, a, 1.1);
    }
    stop = clock(); //ֹͣ��ʱ
    duration = ((double)(stop-start))/CLK_TCK/MAXK; //�������ʱ��
    printf("ticks2 = %f\n", (double)(stop-start)); //���ʱ�Ӵ��
    printf("duration2 = %6.2e\n", duration); //�������ʱ��

    return 0;

}


double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for( i=1; i<=n; i++)
    {
        p += (a[i] * pow(x,i));
    }
    return p;
}

double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for( i=n; i>0; i--)
    {
        p += a[i-1] + x*p;
    }
    return p;
}
