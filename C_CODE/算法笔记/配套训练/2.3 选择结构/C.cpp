#include<stdio.h>




int main() {
    double a, b, c;
    double temp; //中间变量，用于交换位置
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;

    } 
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    if (a > b)
    {
        /* code */
        temp = a;
        a = b;
        b = temp;
    }
    printf("%.2f %.2f %.2f\n", a, b, c);

    return 0;
    
}