/*
    假设有两个递增序列A与B, 要求将它们合并为一个递增序列C。
*/
#include <iostream>

using namespace std;

const int MAX = 100;

int merge(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, index = 0;  // i指向a[0], j指向b[0], index指向c[0]
    
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
    
    while(i < n) c[index++] = a[i++];  // 将序列a的剩余元素加入序列c
    while(j < m) c[index++] = b[j++];  // 将序列b的剩余元素加入序列c

    return index;  // 返回序列c的长度
}

int main() {

    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8};
    int c[MAX];

    int index = merge(a, b, c, 5, 4);

    // 输出合并后的数组c
    for(int i = 0; i < index; i++) {
        cout << c[i] << ' ';
    }
    
    return 0;
}
