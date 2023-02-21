#include<stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) != EOF)
    {
        /* code */
        int M, sum = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &M);
            sum += M;
        } 
        printf("%d\n", sum);
    }
    
    return 0;
}
