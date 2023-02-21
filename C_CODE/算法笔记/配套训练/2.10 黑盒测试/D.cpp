#include<stdio.h>

int main() {
    int  N, num; //sum不能定义在这...
    while (scanf("%d", &N) != EOF)
    {
        /* code */
        if(!N) {    
            break;
        } else {
            int sum = 0;
            for(int i = 0; i < N; i++) {
                scanf("%d", &num);
                sum += num;
            }
            printf("%d\n", sum);
        }     
    }

    return 0;
}
