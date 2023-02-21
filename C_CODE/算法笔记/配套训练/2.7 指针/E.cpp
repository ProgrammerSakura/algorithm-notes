#include<stdio.h>

//输入十个数
void InputNum(int *p) {
    for(int i = 0; i < 10; i++) {
        scanf("%d", p + i);
    }
}

//处理
void Handle(int *p) {
    int max = *p, min = *p;
    int po1, po2; //记录最大值最小值的位置
    for(int i = 0; i < 10; i++) {
        if(*(p + i) > max) {
            max = *(p + i);
            po1 = i;
        } 
        if(*(p + i) < min) {
            min = *(p + i);
            po2 = i;
        }
    }
    int temp1 = *(p + po1);
    *(p + po1) = *(p + 9);
    *(p + 9) = temp1;
    int temp2 = *(p + po2);
    *(p + po2) = *p;
    *p = temp2;
}

//输出数组
void OutputNum(int *p) {
    for(int i = 0; i < 10; i++) {
        printf("%d ", *(p + i));
    }
}


int main() {
    int num[10];
    InputNum(num);
    Handle(num);
    OutputNum(num);

    return 0;
}
