#include<stdio.h>
#include<string.h>

int main() {
    char n1[10], n2[10];
    while (scanf("%s %s", n1, n2) != EOF)
    {
        /* code */
        int sum = 0;
        for (int i = 0; i < strlen(n1); i++)
        {
            /* code */
            for (int j = 0; j < strlen(n2); j++)
            {
                /* code */
                sum += (n1[i] - '0') * (n2[j] - '0');
            }
            
        }
        printf("%d\n", sum);
        
    }
    

    return 0;
}
