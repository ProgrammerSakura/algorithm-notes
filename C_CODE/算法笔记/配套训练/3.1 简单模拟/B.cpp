#include<stdio.h>
#include<string.h>

//用于将字符串中的,号去除
void dispose(char C[]) {
    int len = strlen(C);
    char temp[20] = {0};//临时存储去除逗号后的数组,注意要定义为char类型
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        /* code */
        if(C[i] != ',') {
            temp[j++] = C[i];
        }
    }

    //将去除逗号的数组重新赋值
    for (int i = 0; i < len; i++)
    {
        /* code */
        C[i] = temp[i];
    }
}




int main() {
    char A[20], B[20];
    while (scanf("%s %s", A, B) != EOF)
    {
        /* code */
        dispose(A);
        dispose(B);
        int a, b;
        //利用sscanf将字符串以整型数据输出
        sscanf(A, "%d", &a);
        sscanf(B, "%d", &b);
        printf("%d\n", a + b);
        //注意要将A，B数组重置，因为下次输入可能只覆盖了部分数据
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
    
    return 0;
}
