#include<stdio.h>
#include<string.h>

int main() {
    char *a = "I love China!";
    int n;
    scanf("%d", &n);
    a += n;
    // printf("%s", a);//直接输出数组
    for(int i = 0; i < strlen(a); i++) { //分别输出
        printf("%c", *(a + i));
    }
    
    return 0;
}
