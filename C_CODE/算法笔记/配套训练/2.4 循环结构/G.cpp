#include<stdio.h>
#include<math.h>

int main() {
    int i = 1, sign = 1; //sign ������Ƿ��ţ�i������ʾ��ĸ
    double pi = 0, num = 1, PI; //pi��ʾPI/4
    while (fabs(num) >= 1e-6)
    {
        /* code */
        
        /*      
        num = sign * (1.0 / i);
        sign = -sign;
        pi = pi + num;
        i += 2; 
        */

        pi = pi + num;
        i += 2;
        sign = -sign;
        num = sign * (1.0 / i);

        
    }
    PI = 4 * pi;
    printf("PI = %10.8lf", PI);
    return 0;
}