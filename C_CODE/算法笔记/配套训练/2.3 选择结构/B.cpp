#include<stdio.h>

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    if (a > b) 
    {
        /* code */
        printf("%.2f %.2f\n", b, a); //从小到大输出
    } else {
        printf("%.2f %.2f\n", a, b); //从小到大输出
    }
    return 0;
}