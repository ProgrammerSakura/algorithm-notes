#include <stdio.h>

int main()
{
    double N; //输入的正整数
    int sum;
    while (true)
    {
        /* code */
        scanf("%lf", &N);
        if (N <= 0 || ((int)N != N))
        {
            continue;
        }
        else
        {
            for (int i = 1; i <= N; i++)
            {
                sum += i;
            }
            printf("%d\n", sum);
            break;
        }
    }

    return 0;
}