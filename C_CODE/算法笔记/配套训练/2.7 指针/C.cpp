#include<stdio.h>
#include<string.h>

int main() {
    char *a = "I love China!";
    int n;
    scanf("%d", &n);
    a += n;
    // printf("%s", a);//ֱ���������
    for(int i = 0; i < strlen(a); i++) { //�ֱ����
        printf("%c", *(a + i));
    }
    
    return 0;
}
