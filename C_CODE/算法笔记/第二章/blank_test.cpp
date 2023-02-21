#include<stdio.h>

/* int main() {
    char str[10];
    scanf("%s", str);
    printf("%s", str);
    return 0;    
} */


//测试scanf的%c格式是否可以读入空格跟换行
int main() {
    int a;
    char c, str[10];
    scanf("%d%c%s", &a, &c, str);
    printf("a = %d, c = %c, str = %s ", a, c, str); 
    return 0;
}