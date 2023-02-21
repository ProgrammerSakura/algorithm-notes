#include<stdio.h>

/*
    错误思想：不能直接写num[n][n],编译阶段数组还没有分配内存；
    解题思路：观察该图形为二维，考虑用二维数组来进行存储，注意到每一行第一列都为一，当行号与列号都相等的时候也为1，即当j==1或者i==j时为1，其他情况的元素为它的上方元素加上它的上方左边元素之和也就是num[i-1][j-1] + num[i-1][j]。

*/

int main() {
   int n;
   scanf("%d", &n);
   int num[10][10];
   //判断是否超出n的范围,超出则直接返回
   if(n > 10) 
    return 0;
   for(int i = 1; i <= n; i++) { //输出行
       for(int j = 1; j <= i; j++) { //输出列
           if(j == 1 || i == j) { //值为一的情况
               num[i][j] = 1;
           } else {
               num[i][j] = num[i-1][j-1] + num[i-1][j]; 
           }
       }
   }

   //输出杨辉三角
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= i; j++) {
           printf("%d ", num[i][j]);
       }
       printf("\n"); //每行输出后换行。
   }

   return 0;
}

