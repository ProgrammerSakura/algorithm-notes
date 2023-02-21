#include<stdio.h>
//思路一：层次性赋值来求
/*
int main() {
    int n, i, F, F1 = 1, F2 = 1;
    scanf("%d", &n);
    for(i = 3; i <= n; i++) { //出错：i == 3....
        F =F1 + F2;
        F1 = F2;
        F2 = F;
    }
        
   printf("%d", F);
    
}
*/

//思路二 利用数组来求
//斐波那契数列
#include<stdio.h>
int main() {
	int a[51] ={0, 1, 1};// 便于数组下标对齐
    int n,i;
    scanf("%d", &n);
    for(i = 3; i<=n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    printf("%d", a[n]);
}
