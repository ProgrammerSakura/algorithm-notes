#include<stdio.h>
//˼·һ������Ը�ֵ����
/*
int main() {
    int n, i, F, F1 = 1, F2 = 1;
    scanf("%d", &n);
    for(i = 3; i <= n; i++) { //����i == 3....
        F =F1 + F2;
        F1 = F2;
        F2 = F;
    }
        
   printf("%d", F);
    
}
*/

//˼·�� ������������
//쳲���������
#include<stdio.h>
int main() {
	int a[51] ={0, 1, 1};// ���������±����
    int n,i;
    scanf("%d", &n);
    for(i = 3; i<=n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    printf("%d", a[n]);
}
