#include<stdio.h>

int main() {
    int L, M;
    while (scanf("%d%d", &L, &M) != EOF)
    {
        /* code */
        if(L == 0 && M == 0) break;
        int left, right;
        int tree[10000] = {0};//����������Ԫ�س�ʼ��Ϊ0����0����ʾ����һ������
        //���˵�֮������������1
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
        int num = 0;//��¼��ǰʣ�µ����ĸ���
        for (int i = 0; i <= L; i++)
        {
            /* code */
            if(tree[i] == 0) num++;
        }
        printf("%d\n", num);
        
        
    }
    
    return 0;
}
