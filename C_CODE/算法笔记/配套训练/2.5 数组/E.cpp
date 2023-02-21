#include<stdio.h>
#include<string.h>

int main() {
   char str1[10], str2[10];
   int i;
   gets(str1);
   gets(str2);
  /*  for(int i = 0; i < 10; i++) {
       if(str1[i] != str2[i]) {
           printf("%d\n", str1[i] - str2[i]);
           return 0;
       } 
   }
   if(str1[i] == str2[i])
        printf("0");
 */
    int num = strcmp(str1,str2);
    printf("%d", num);
   return 0;
}
