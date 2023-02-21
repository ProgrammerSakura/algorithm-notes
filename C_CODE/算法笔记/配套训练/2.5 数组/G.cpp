#include<stdio.h>

int main() {
   /* int n1 = 1, n2 = 1;
   printf("%d\n%d\n", n1, n2);
   int num;
   num = n1 + n2;
   for(int i = 3; i <= 20; i++) {
       num = n1 + n2;
       printf("%d\n", num);
       n1 = n2;
       n2 = num; 
    }
       */

    //思路二：考虑用数组进行存储
    int fibo[20] = {1, 1};
    //给Fibonacci数列前20项赋值
    for(int i = 2; i < 20; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    //输出Fibonacci数列
    for(int i = 0; i < 20; i++) {
        printf("%d\n", fibo[i]);
    }
    
   


   return 0;
}
