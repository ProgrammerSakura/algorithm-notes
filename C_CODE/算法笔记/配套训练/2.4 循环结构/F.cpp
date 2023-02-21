#include<stdio.h>

//简单方法
/* 
    算法思想：
        经观察，输出的结果为一个四行五列的矩阵，第一行为1*1，1*2……，第二行为2*1，2*2……，同理三四行一样，故考虑利用
 */
int main()
{
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 5; j++){
            printf("%3d", i * j);
            if(j == 5)
                printf("\n");
        }
    }
}



/* 复杂方法
int main() {
    int num = 1;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 1;
        if(i == 1) 
            printf("\n");
    }
    num = 2;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 2;
        if(i == 1) 
            printf("\n");
    }
    num = 3;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 3;
        if(i == 1) 
            printf("\n");
    }
    num = 4;
    for(int i = 5; i >= 1;i--) {
        printf("%3d", num);
        num += 4;
        if(i == 1) 
            printf("\n");
    }
    return 0;
} */