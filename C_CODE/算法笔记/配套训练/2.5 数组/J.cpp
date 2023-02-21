#include<stdio.h>
#include<string.h>

int main() {
   char str1[10],str2[10],str3[10];
   gets(str1);
   gets(str2);
   gets(str3);
   int cmp1 = strcmp(str1, str2);
   if(cmp1 > 0) {
       int cmp2 = strcmp(str1, str3);
       if(cmp2 > 0) {
           puts(str1);
       } else {
           puts(str3);
       }
   } else {
       int cmp3 = strcmp(str2, str3);
       if(cmp3 > 0) {
           puts(str2);
       } else {
           puts(str3);
       }
   }
   return 0;
}
