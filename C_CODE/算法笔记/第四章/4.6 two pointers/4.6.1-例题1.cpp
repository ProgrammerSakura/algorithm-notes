/**  @author 吴佳
  *  给定一个递增的正整数序列和一个正整数 M, 求序列中的两个不同位置的数a和 b, 使得它们的和恰好为 M,输出所有满足条件的方案
*/

#include<iostream>

using namespace std;

// 算法一：O(n^2)
void addM1(int a[], int n, int M) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == M) {
                cout << a[i] << ' ' << a[j] << endl;
            }
        }
    }
}

// 算法二：O(n)
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