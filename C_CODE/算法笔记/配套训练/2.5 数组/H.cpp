#include<stdio.h>

int main() {
    int num[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    //排序
    for(int i = 1; i <= 9; i++) {  //进行9趟排序
        //每一趟排序进行比较
        for(int j = 0; j < 10 - i; j++) {
            if(num[j] > num[j + 1]) { //左边大则交换
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp; 
            }
        }
    }

    //输出排序结果
    for(int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
    }

   return 0;
}
