#include<stdio.h>
#include<string.h>

//���ڽ��ַ����е�,��ȥ��
void dispose(char C[]) {
    int len = strlen(C);
    char temp[20] = {0};//��ʱ�洢ȥ�����ź������,ע��Ҫ����Ϊchar����
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        /* code */
        if(C[i] != ',') {
            temp[j++] = C[i];
        }
    }

    //��ȥ�����ŵ��������¸�ֵ
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
        //����sscanf���ַ����������������
        sscanf(A, "%d", &a);
        sscanf(B, "%d", &b);
        printf("%d\n", a + b);
        //ע��Ҫ��A��B�������ã���Ϊ�´��������ֻ�����˲�������
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
    
    return 0;
}
