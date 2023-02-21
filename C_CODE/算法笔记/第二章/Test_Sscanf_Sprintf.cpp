#include<stdio.h>

int main() {
    int n = 12;
    double db;
    char str1[100] = "2048:3.14,hello", str2[100];
    sscanf(str1, "%d:%lf,%s", &n, &db, str2);//将str1中的内容按照%d:%lf,%s的格式写到变量n,db,str2中
    printf("n = %d, db = %.2f, str2 = %s\n", n, db, str2);

    int n2 = 12;
    double db2 = 3.1415;
    char str3[100], str4[100] = "good";
    sprintf(str3, "%d:%0.2f,%s", n2, db2, str4);//将n,db2,str4中的数据写到数组str3中
    printf("str = %s\n", str3);

    return 0;

}