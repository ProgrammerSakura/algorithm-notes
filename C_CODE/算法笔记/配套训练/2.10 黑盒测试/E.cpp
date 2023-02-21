#include<stdio.h>

int main() {
    int N, M;
    scanf("%d", &N);
    while (N--)
    {
        /* code */
        scanf("%d", &M);
        int sum = 0, num;
        for(int i = 0; i < M; i++) {
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
    

    return 0;
}
