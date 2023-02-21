#include<stdio.h>

int main() {
    int sum;
    for(int i = 1; ; i++) {
        sum += i;
        if(sum > 1000) {
            printf("%d\n", i); 
            break;
        }
    }
    return 0;
}