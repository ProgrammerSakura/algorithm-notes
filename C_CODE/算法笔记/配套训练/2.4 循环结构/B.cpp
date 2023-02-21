#include<stdio.h>

int main() {
    int i = 1;
    int sum = 0;
    do
    {
        /* code */
        sum += i;
        i++;
    } while (i <= 100);
    printf("%d", sum);
}