/**  @author ���
  *  ����һ�����������������к�һ�������� M, �������е�������ͬλ�õ���a�� b, ʹ�����ǵĺ�ǡ��Ϊ M,����������������ķ���
*/

#include<iostream>

using namespace std;

// �㷨һ��O(n^2)
void addM1(int a[], int n, int M) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == M) {
                cout << a[i] << ' ' << a[j] << endl;
            }
        }
    }
}

// �㷨����O(n)
void addM2(int a[], int n, int M) {
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == M) {
            cout << a[i] << ' ' << a[j] << endl;
            i++;
            j--;
        } else if(a[i] + a[j] < M){
            i++;
        } else {
            j--;
        }
    }
}

int main() {

    int a[] = {1, 2, 3, 4, 5, 6};
    int M = 8;

    addM2(a, 6, M);

    return 0;
}