#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    while (N--)
    {
        /* code */
        int M, num, sum = 0;
        scanf("%d", &M);
        for(int i = 0; i < M; i++) {
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
        printf("\n");
    }
    

    return 0;
}
