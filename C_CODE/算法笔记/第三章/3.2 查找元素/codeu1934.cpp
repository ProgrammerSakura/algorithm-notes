#include<cstdio>

int main() {
    int n;
    while (scanf("%d", &n) != EOF)
    {
        /* code */
        int a[200];
        for (int i = 0; i < n; i++)
        {
            /* code */
            scanf("%d", &a[i]);
        }
        int x;
        scanf("%d", &x);
        for (int i = 0; i < n; i++)
        {
            /* code */
            if(x == a[i]) {
                printf("%d\n", i);
                break;
            } else if(i == n-1){
                printf("-1");
                break;
            }
        }
        
        
    }
    

    return 0;
}
