#include<stdio.h>
#include<string.h>

//memset �������е�ÿһ��Ԫ�ؽ��и�ֵ
int main() {
    int a[5] = {1,2,1,4,6};
    //�������е�Ԫ�ظ�ֵΪ0
    memset(a, 0, sizeof(a));
    for(int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    //����
    printf("\n");
    //��ֵΪ-1
    memset(a, -1, sizeof(a));
    for(int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }

    return 0;
}