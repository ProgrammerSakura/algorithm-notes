#include<stdio.h>

int main() {
   double i = 1, j = 2, num, temp; //i,j当作分子分母,num为分数，temp用来临时存储变量
   int count; //用来计数
   double sum = 0;//和
   for(count = 1; count <= 20; count++) {
       num = j / i;
       temp = i;
       i = j;
       j = temp + j;
       sum += num;
    }
    printf("%.6f", sum);
    return 0;
}
