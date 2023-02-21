#include<stdio.h>

int main() {
    int L, M;
    while (scanf("%d%d", &L, &M) != EOF)
    {
        /* code */
        if(L == 0 && M == 0) break;
        int left, right;
        int tree[10000] = {0};//将数组所有元素初始化为0，用0来表示存在一棵树。
        //将端点之间的所有数变成1
        for (int i = 0; i < M; i++)
        {
            /* code */
            scanf("%d%d", &left, &right);
            for (int j = left; j <= right; j++)
            {
                /* code */
                tree[j] = 1;
            }
            
        }
        int num = 0;//记录当前剩下的数的个数
        for (int i = 0; i <= L; i++)
        {
            /* code */
            if(tree[i] == 0) num++;
        }
        printf("%d\n", num);
        
        
    }
    
    return 0;
}
