#include<stdio.h>

int main() {
    int num[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    //����
    for(int i = 1; i <= 9; i++) {  //����9������
        //ÿһ��������бȽ�
        for(int j = 0; j < 10 - i; j++) {
            if(num[j] > num[j + 1]) { //��ߴ��򽻻�
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp; 
            }
        }
    }

    //���������
    for(int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
    }

   return 0;
}
