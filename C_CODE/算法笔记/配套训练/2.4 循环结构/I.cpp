#include<stdio.h>

int main() {
   double i = 1, j = 2, num, temp; //i,j�������ӷ�ĸ,numΪ������temp������ʱ�洢����
   int count; //��������
   double sum = 0;//��
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
