#include<stdio.h>

int main() {
    int a[10];
    //对数组进行初始化
    for(int i = 0; i < 10; i++ ) {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= 9; i++) { //进行n-1趟排序
        //第i趟从a[0]到a[n-i-1]都与它们下一个数进行比较
        /* 
            注：第一趟a[0]到a[8]都需要与下一个数进行比较，第二趟a[0]到a[7]都需要与下一个数进行比较，
            以此类推，第i趟从a[0]到a[n-i-1]都与它们下一个数进行比较
         */
        for(int j = 0; j < 10 - i; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    //打印排序后的结果
    for(int i = 0; i < 10; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}