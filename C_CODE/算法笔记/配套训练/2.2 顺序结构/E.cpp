#include<stdio.h>
#include<math.h>

int main() {
    double a, b, c;//ϵ��
    double dert;//�б�ʽ
    double r1, r2;//��
   
    while (true)
    { 
        printf("��ֱ�����÷��̵�����ϵ����");
        scanf("%lf%lf%lf", &a, &b, &c);
        dert = b * b - 4 * a * c;
        if ( a != 0 && ( dert >= 0 ) )
        {
            /* code */
        
            r1 = ( -b + sqrt(dert) ) / (2 * a);
            r2 = ( -b - sqrt(dert) ) / (2 * a);
            printf("r1=%7.2f\n", r1);
            printf("r2=%7.2f\n", r2);
            break;
        } else if ( a == 0) {
            printf("ϵ��a����Ϊ0�����������룡\n");
        } else {
            printf("�÷����޽⣬���������룡\n");
        }
    }
   
    return 0;
    
}