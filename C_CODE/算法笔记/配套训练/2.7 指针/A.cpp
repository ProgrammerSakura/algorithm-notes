#include<stdio.h>

void compare(int *a, int *b) {
    if(*a > *b) {
        printf("%d %d", *a, *b);
    } else {
        printf("%d %d", *b, *a);
    }

}

int main() {
   int a, b;
   scanf("%d%d", &a, &b);
   int *p1 = &a, *p2 = &b;
   compare(p1, p2);

   return 0;
}
