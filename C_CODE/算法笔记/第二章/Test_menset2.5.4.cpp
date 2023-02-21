#include<stdio.h>
#include<string.h>

//memset 对数组中的每一个元素进行赋值
int main() {
    int a[5] = {1,2,1,4,6};
    //将数组中的元素赋值为0
    memset(a, 0, sizeof(a));
    for(int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    //换行
    printf("\n");
    //赋值为-1
    memset(a, -1, sizeof(a));
    for(int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }

    return 0;
}