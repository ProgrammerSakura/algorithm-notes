#include<stdio.h>
#include<string.h>

//交换指针指向
void swap(char *&a, char *&b) {
    char *temp = a;
    a = b;
    b = temp;
}

int main() {
    char str1[20], str2[20], str3[20];
    gets(str1);
    gets(str2);
    gets(str3);
    char *p1 = str1, *p2 = str2, *p3 = str3;
    
    //比较大小
    int cmp1, cmp2, cmp3;
    cmp1 = strcmp(p1, p2);
    if(cmp1 > 0) swap(p1, p2);
    cmp2 = strcmp(p2, p3);
    if(cmp2 > 0) swap(p2, p3);
    cmp3 = strcmp(p1, p2);
    if(cmp3 > 0) swap(p1, p2);

    //输出
    puts(p1);
    puts(p2);
    puts(p3);

    return 0;
}
