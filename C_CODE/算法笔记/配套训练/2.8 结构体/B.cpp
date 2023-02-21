#include<stdio.h>
#include<string.h>

struct student {
    int num;
    char name[20];
    char sex;
    int age;
    //对结构体进行初始化
    student() {}
    student(int _num, char _name[], char _sex, int _age) {
        num = _num;
        strcpy(name, _name);
        sex = _sex;
        age = _age;

    }
};

int main() {
    student stu[20];
    student *p = stu;
    int n;
    int num, age;
    char name[20], sex;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        //使用构造函数赋值
        /* scanf("%d %s %c %d",&num, name, &sex, &age); //注意不要写成%d%s%c%d，因为%c格式可以读入空格和换行。
        stu[i] = student(num, name, sex, age); */
        scanf("%d %s %c %d",&(p + i)->num, &(p + i)->name, &(p + i)->sex, &(p + i)->age);

    }

    for(int i = 0; i < n; i++) {
        printf("%d %s %c %d\n", (p + i)->num, (p + i)->name, (p + i)->sex, (p + i)->age);
    }

    return 0;
}
