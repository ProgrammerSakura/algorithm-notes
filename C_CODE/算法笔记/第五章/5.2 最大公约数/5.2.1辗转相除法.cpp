#include<stdio.h>

int gcb(int a, int b) {
    if(b == 0) return a;
    else return gcb(b, a % b);
}

int main() {
    
    int a, b;
 
    scanf("%d%d", &a, &b);

    printf("���Լ��Ϊ��%d", gcb(a, b));
    
    return 0;
}
