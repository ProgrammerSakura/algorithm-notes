#include<stdio.h>

/* int main() {
    char str[10];
    scanf("%s", str);
    printf("%s", str);
    return 0;    
} */


//����scanf��%c��ʽ�Ƿ���Զ���ո������
int main() {
    int a;
    char c, str[10];
    scanf("%d%c%s", &a, &c, str);
    printf("a = %d, c = %c, str = %s ", a, c, str); 
    return 0;
}