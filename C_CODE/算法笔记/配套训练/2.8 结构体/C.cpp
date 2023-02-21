#include<stdio.h>

struct {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int class1;//class是关键字
        char position[10];
    }category;
}stu_tch[100];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %s %c %c", &stu_tch[i].num, stu_tch[i].name, &stu_tch[i].sex, &stu_tch[i].job);
        if(stu_tch[i].job == 's') {
            scanf("%d", &stu_tch[i].category.class1);
        } else if(stu_tch[i].job == 't') {
            scanf("%s", stu_tch[i].category.position);
        }
    }

    for(int i = 0; i < n; i++) {
        //若为学生
        if(stu_tch[i].job == 's') {
            printf("%d %s %c %c %d\n",  stu_tch[i].num, stu_tch[i].name, stu_tch[i].sex, stu_tch[i].job, stu_tch[i].category.class1);
        } else if(stu_tch[i].job == 't') {
            printf("%d %s %c %c %s\n",  stu_tch[i].num, stu_tch[i].name, stu_tch[i].sex, stu_tch[i].job, stu_tch[i].category.position);
        }
            
    }



    return 0;
}
