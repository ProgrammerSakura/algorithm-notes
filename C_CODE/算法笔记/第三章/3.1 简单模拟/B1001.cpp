#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int step = 0;
    while (n != 1)
    {
        /* code */
        if(n % 2 == 0) {
            n = n / 2;
            step++;
        } else if(n % 2 == 1) {
            n = (3 *n + 1) / 2; 
            step++;
        }

    }
    printf("%d", step);
    
    
    return 0;
}
