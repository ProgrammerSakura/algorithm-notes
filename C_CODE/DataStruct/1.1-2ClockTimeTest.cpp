#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAXN 101 //多项式最大项数，即多项式阶数+1 note:太久没写C语言忘记宏是不能加标点符号了....
#define MAXK 1e7 //被测函数最大重复调用次数


clock_t start,stop;
double duration;

/**
    clock（）：捕捉从程序开始运行到clock（）被调用时所耗费的时间。这个时间单位是clock tick，即“时钟打点”
    常数CLKTCK：机器时钟每秒所走的时钟打点数。
*/

//声明函数
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

//主函数
int main()
{
    int i;
    double a[MAXN]; //存储多项式系数

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

    start = clock();   //开始计时
    for(i=0; i<MAXK; i++)
    {
        f1(MAXN-1, a, 1.1);
    }
    stop = clock(); //停止计时
    duration = ((double)(stop-start))/CLK_TCK/MAXK; //计算花费的时间
    printf("ticks1 = %f\n", (double)(stop-start)); //输出时钟打点
    printf("duration = %6.2e\n", duration); //输出持续时间

    start = clock();   //开始计时
    for(i=0; i<MAXK; i++)
    {
        f2(MAXN-1, a, 1.1);
    }
    stop = clock(); //停止计时
    duration = ((double)(stop-start))/CLK_TCK/MAXK; //计算持续时间
    printf("ticks2 = %f\n", (double)(stop-start)); //输出时钟打点
    printf("duration2 = %6.2e\n", duration); //输出持续时间

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
