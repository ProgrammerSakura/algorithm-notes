#include<stdio.h>

struct competitor {
    int num; //ѧУ��ż��ɼ�
    int grade;
} cmpttr[105];


int main() {
    int N;
    int total1 = 0, total2 = 0, total3 = 0;
    int record1, record2, record3;
    int school[100000] = {0};//����ѧУ�ܳɼ�
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &cmpttr[i].num);
        scanf("%d", &cmpttr[i].grade);
        school[cmpttr[i].num] += cmpttr[i].grade;
    }

    int MAX = -1, k = 0;
    for (int i = 1; i <= N; i++)
    {
        /* code */
        if(school[i] > MAX) {
            MAX = school[i];
            k = i;
        }

    }
    printf("%d %d", k, MAX);
    

    // for(int i = 0; i < N; i++) {
    //     if(cmpttr[i].num == 1) {
    //         total1 += cmpttr[i].grade;
    //         record1 = total1;
    //     } 
    //     if(cmpttr[i].num == 2) {
    //         total2 += cmpttr[i].grade;
    //         record2 = total2;
    //     } 
    //     if(cmpttr[i].num == 3) {
    //         total3 += cmpttr[i].grade;
    //         record3 = total3;
    //     } 

    // }

    // //�Ƚϴ�С
    // if(total1 > total2) {
    //     int temp = total1;
    //     total1 = total2;
    //     total2 = temp;
    // } 

    // if(total2 > total3) {
    //     int temp = total2;
    //     total2 = total3;
    //     total3 = temp;
    // }

    // if(total1 > total2) {
    //     int temp = total1;
    //     total1 = total2;
    //     total2 = temp;
    // } 

    // if(total3 == record1) {
    //     printf("%d ", 1);
    // } else if(total3 == record2) {
    //     printf("%d ", 2);
    // } else {
    //     printf("%d ",3);
    // }
    // printf("%d\n", total3);

    

    return 0;
}

// #include<cstdio>
// const int maxn = 100010;
// int school[maxn] = {0}; //����ÿ��ѧУ���ܳɼ�

// int main() {
//     int n, schID, score;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         //����ѧУID������
//         scanf("%d%d", &schID, &score);
//         //��¼ѧУ���ܷ�
//         school[schID] += score;
//     }

//     int MAX = -1, token = 1; //��߷ּ���߷�ѧУ���
//     //ѡ���ܷ���ߵ�ѧУ
//     for(int i = 0; i < n; i++) {
//         if(school[i] > MAX) {
//             MAX = school[i];
//             token = i;
//         }
//     }
//     printf("%d %d\n", token, MAX);

//     return 0;
// }
