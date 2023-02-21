#include<stdio.h>

int main() {
    int n;
    int num[1000];
    while (scanf("%d", &n) != EOF)
    {
        /* code */
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            scanf("%d", &num[i]);
            if(num[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if(even > odd) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        
    }
    

    return 0;
}
