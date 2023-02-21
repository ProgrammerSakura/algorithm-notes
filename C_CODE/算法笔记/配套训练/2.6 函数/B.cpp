#include<stdio.h>
#include<string.h>

void vowels(char s1[], char s2[]) {
    int n = strlen(s1);
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == '0' || s1[i] == 'u') {
            s2[j] = s1[i];
            j++;
        }
    }
    //注意要在s2的末尾处加上字符串结束符号
    s2[j] = '\0';
}

int main() {
    char str1[10], str2[10];
    gets(str1);
    vowels(str1, str2);
    puts(str2);
    return 0;
}
