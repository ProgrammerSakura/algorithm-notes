#include<stdio.h>
#include<string.h>

struct person {
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0}; //�ṹ�������ʼ��

int main() {
    int n;
    char name[20];
    scanf("%d", &n);
    getchar();//��������Ļ��з��š�
    for(int i = 0; i < n; i++) {
        // scanf("%s", name);
        gets(name);
        //ѭ���ж�������ĺ�ѡ�˼�Ʊ��
        for(int j = 0; j < 3; j++) {
            if(strcmp(name, leader[j].name) == 0) {
                leader[j].count++;
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        printf("%s:%d\n",leader[i].name, leader[i].count);
    }

    return 0;
}
