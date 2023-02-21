#include<stdio.h>

int main() {
   int a[2][3], b[3][2];
   for(int i = 0; i < 2; i++) {
       for(int j = 0; j < 3; j++) {
           scanf("%d", &a[i][j]);
       }
   }

    //ÐÐÁÐ»¥»»
   for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 2; j++) {
           b[i][j] = a[j][i];
           printf("%d ", b[i][j]);
       }
       printf("\n");
   }


   return 0;
}
