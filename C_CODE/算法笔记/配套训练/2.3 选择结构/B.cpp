#include<stdio.h>

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    if (a > b) 
    {
        /* code */
        printf("%.2f %.2f\n", b, a); //��С�������
    } else {
        printf("%.2f %.2f\n", a, b); //��С�������
    }
    return 0;
}