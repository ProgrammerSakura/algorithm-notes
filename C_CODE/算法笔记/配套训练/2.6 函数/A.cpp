#include<stdio.h>
#include<string.h>

void reserve(char str[]) {  //һά���鲻��Ҫ��д���鳤�ȣ���ά����ֻ��Ҫ��д�ڶ�ά�ȵĳ���
    int len = strlen(str);
    //˼·һ��������һ������洢���������
    /* char tempStr[20];
    for(int i = 0; i < len; i++) {
        tempStr[i] = str[i];
    }

    for(int i = 0; i < len; i++) {
        str[i] = tempStr[len - i - 1];
    } */

    //˼·����������Ԫ�طֳ����룬����˳��
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    
} //������Ϊ������ʱ�򣬶�������޸ľ��൱��ֱ�Ӷ�ԭ����Ԫ�ص��޸�

int main() {
   char str[20];
   gets(str);
   reserve(str);
   puts(str);

   return 0;
}
