#include<stdio.h>

struct Student {
    int num;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
    double average;
}stu[10];

//���ѧ��ƽ����
void getAverage() {
    for(int i = 0; i < 10; i++) {
        scanf("%d %s %d %d %d", &stu[i].num, stu[i].name, &stu[i].grade1, &stu[i].grade2, &stu[i].grade3);
        stu[i].average = (stu[i].grade1 + stu[i].grade2 + stu[i].grade3) / 3; 
    }
}

//�Ƚ�ƽ���ɼ�,�õ�ƽ���ɼ�����ѧ�����
int compare() {
    int max = stu[0].average, po;
    for(int i = 0; i < 10; i++) {
        if(stu[i].average > max) {
            max = stu[i].average;
            po = i;
        }
    }
    return po;
}

//�����ƽ���ɼ�
void totalAvrg() {
    double aver1 = stu[0].grade1, aver2 = stu[0].grade2, aver3 = stu[0].grade3;
    for(int i = 1; i < 10; i++) {
        aver1 = aver1 + stu[i].grade1;
        aver2 = aver2 + stu[i].grade2;
        aver3 = aver3 + stu[i].grade3;
    }
    aver1 = aver1 / 10;
    aver2 = aver2 / 10;
    aver3 = aver3 / 10;
    printf("%.2f %.2f %.2f\n", aver1, aver2, aver3);
}


//��ӡ����ƽ���ɼ������ͬѧ��Ϣ
void Print() {
    getAverage();
    int po = compare();
    totalAvrg();
    printf("%d %s %d %d %d\n", stu[po].num, stu[po].name, stu[po].grade1, stu[po].grade2, stu[po].grade3);
    
}

int main() {
    Print();
    return 0;
}
