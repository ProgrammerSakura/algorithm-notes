#include<stdio.h>

int main() {
   int num[10];
   for(int i = 0; i < 10; i++) {
       scanf("%d",&num[i]);
   }
   //Ïà·´Ë³ĞòÊä³ö
   for(int i = 9; i >=0; i--) {
       printf("%d\n", num[i]);
   }
//1 2 3 4 5 6 7 8 9 0
   return 0;
}
