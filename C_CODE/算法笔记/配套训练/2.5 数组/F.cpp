#include<stdio.h>

int main() {
   int num[10];
   for(int i = 0; i < 10; i++) {
       scanf("%d", &num[i]);
   }
   //ÄæĞòÊä³ö
   for(int i = 9; i >= 0; i--) {
       printf("%d ", num[i]);
   }

   return 0;
}
