#include<stdio.h>

//�������ֳ��õ������ʽ
int main() {
    int a = 123, b = 1234567;
    double d1 = 12.3456;
    //%md ʹ����mλ��int������mλ�����Ҷ������
    printf("%5d\n", a);
    printf("%5d\n", b);

    printf("---------------\n");

    //%0md ����������mλʱ��ǰ�油0�����
    printf("%05d\n", a);
    printf("%05d\n", b);


    printf("---------------\n");
    //%.mf �ø���������mλС�����������ָ���Ǿ��ȵġ������������˫��
    printf("%.0f\n", d1);
    printf("%.1f\n", d1);
    printf("%.2f\n", d1);
    printf("%.3f\n", d1);   
    printf("%.4f\n", d1);  

    return 0;
}