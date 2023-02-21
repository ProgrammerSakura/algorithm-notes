#include<stdio.h>
#include<string.h>

void reserve(char str[]) {  //一维数组不需要填写数组长度，二维数组只需要填写第二维度的长度
    int len = strlen(str);
    //思路一：用另外一个数组存储，逆序输出
    /* char tempStr[20];
    for(int i = 0; i < len; i++) {
        tempStr[i] = str[i];
    }

    for(int i = 0; i < len; i++) {
        str[i] = tempStr[len - i - 1];
    } */

    //思路二：将数组元素分成两半，交换顺序
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    
} //数组作为参数的时候，对数组的修改就相当与直接对原数组元素的修改

int main() {
   char str[20];
   gets(str);
   reserve(str);
   puts(str);

   return 0;
}
