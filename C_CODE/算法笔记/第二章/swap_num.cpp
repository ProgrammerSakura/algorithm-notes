#include<stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/* //????????1
void swap(int *a, int *b) {
    int i;
    int* temp;
    //??temp??????????
    temp = &i;
    *temp =*a;
    *a = *b;
    *a = *temp;
} */

//????????2
/* void swap(int *a, int *b) {
    int* temp = a;
    a = b; 
    b = temp;
}
 */
int main() {
   int a = 1, b = 2;
   int *p1 = &a, *p2 = &b;
   swap(p1, p2);
   printf("a=%d, b=%d", a, b);

   return 0;
}
