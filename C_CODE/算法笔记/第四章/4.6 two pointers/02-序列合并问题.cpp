/*
    ������������������A��B, Ҫ�����Ǻϲ�Ϊһ����������C��
*/
#include <iostream>

using namespace std;

const int MAX = 100;

int merge(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, index = 0;  // iָ��a[0], jָ��b[0], indexָ��c[0]
    
    while (i < n && j < m) {
        if(a[i] <= b[j]) {
            c[index] = a[i];
            index++;
            i++;
        } else {
            c[index] = b[j];
            index++;
            j++;
        }
    }
    
    while(i < n) c[index++] = a[i++];  // ������a��ʣ��Ԫ�ؼ�������c
    while(j < m) c[index++] = b[j++];  // ������b��ʣ��Ԫ�ؼ�������c

    return index;  // ��������c�ĳ���
}

int main() {

    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8};
    int c[MAX];

    int index = merge(a, b, c, 5, 4);

    // ����ϲ��������c
    for(int i = 0; i < index; i++) {
        cout << c[i] << ' ';
    }
    
    return 0;
}
