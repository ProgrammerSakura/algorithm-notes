#include<stdio.h>
#include<string.h>
/* 
    ASCII码 a-z：97-122
            A-Z：65-90
            0-9：48-57
 */

int main() {
   char str[100];
   scanf("%s", str);
   int len = strlen(str);
   for(int i = 0; i < len; i++) {
       if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'z' - (str[i] - 'a');//或者写成str[i] = 219 - str[i]
       } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'Z' - (str[i] - 'A');//或者写成str[i] = 155 - str[i]
       }
            
   }
   printf("%s", str);

   return 0;
}
