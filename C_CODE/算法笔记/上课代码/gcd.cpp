#include<stdio.h>

// �������⹫Լ��
int gcb(int a, int b) {
    
    if(a == 0 || b == 0) 
        return a + b;  // 8 0 ��Լ��Ϊ0

    int t = 1, min_num;
    
    if(a < b) 
        min_num = a;
    else 
        min_num = b;

    for(int i = 2; i <= min_num; i++) {
        if(a % i == 0 && b % i == 0) {
            if(t < i) {
                t = i;  // ��¼���Լ��
            }
        }
    }

    return t;
}

int main() {
    
    int a, b;
 
    scanf("%d%d", &a, &b);

    printf("���Լ��Ϊ��%d", gcb(a, b));
    
    return 0;
}
