#include<stdio.h>

struct Student {
    int num;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
}stu[5];

void Input() {
    for(int i = 0; i < 5; i++) {
        scanf("%d %s %d %d %d", &stu[i].num, stu[i].name, &stu[i].grade1, &stu[i].grade2, &stu[i].grade3);
    }
}

void Print() {
    for(int i = 0; i < 5; i++) {
        printf("%d %s %d %d %d\n", stu[i].num, stu[i].name, stu[i].grade1, stu[i].grade2, stu[i].grade3);
    }
}



int main() {
    Input();
    Print();

    return 0;
}
