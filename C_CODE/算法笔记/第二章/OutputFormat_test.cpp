#include<stdio.h>

//测试三种常用的输出格式
int main() {
    int a = 123, b = 1234567;
    double d1 = 12.3456;
    //%md 使不足m位的int变量以m位进行右对齐输出
    printf("%5d\n", a);
    printf("%5d\n", b);

    printf("---------------\n");

    //%0md 当变量不足m位时候前面补0来输出
    printf("%05d\n", a);
    printf("%05d\n", b);


    printf("---------------\n");
    //%.mf 让浮点数保留m位小数输出，保留指的是精度的“四舍六入五成双”
    printf("%.0f\n", d1);
    printf("%.1f\n", d1);
    printf("%.2f\n", d1);
    printf("%.3f\n", d1);   
    printf("%.4f\n", d1);  

    return 0;
}