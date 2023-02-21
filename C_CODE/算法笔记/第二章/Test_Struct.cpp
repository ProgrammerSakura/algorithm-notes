#include<stdio.h>

struct Point {
    int x, y;
    //不初始化
    Point(){};
    Point(int _x, int _y): x(_x), y(_y) {};
}pt[10];

int main() {
   int num = 10;
   for(int i = 1; i <= 3; i++) {
       for(int j = 1; j <= 3; j++) {
           pt[num++] = Point(i, j); //初始化结构体数组中的元素的x,y;
       }
   }
   //打印出每个数组的x,y值
   for(int i = 0; i < num; i++) {
       printf("%d,%d\n", pt[i].x, pt[i].y);
   }

   return 0;
}
