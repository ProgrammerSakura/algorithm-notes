#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<ctime>
#include<cmath>

using namespace std;

const int N = 10;

class Sort {

    // ѡ������
    /*
        ÿ�δ�������ѡ����С��Ԫ��
    */
    public: 
        void selection_sort(int a[], int n) {
            for(int i = 0; i < n; i++) {
                int k = i;
                // ѡ��[i, n-1]����С��Ԫ�أ��±�Ϊk
                for(int j = i; j < n; j++) {
                    if(a[k] > a[j]) {
                        k = j;
                    }
                }
                // ����a[k]��a[i]
                swap(a[k], a[i]);
            }
        }

        // �Ӻ������Ԫ�ص�ǰ�����ź���������С�
        void insert_sort(int a[], int n) {
            for(int i = 1; i < n; i++) {  // �ӵڶ���Ԫ�ؿ�ʼ
                if(a[i] < a[i - 1]) {
                    int temp = a[i];  // temp�ݴ�a[i]
                    int j = i - 1;  // ��i - 1��ʼ��ǰö��
                    while(j >= 0 && temp < a[j]) {  // ֻҪtempС�ڵ�ǰԪ��
                        a[j + 1] = a[j];  // ���д���temp��Ԫ�ض�������
                        j--;
                    }
                    // for (int j = i - 1; j >= 0 && a[j] > temp; j--) {
                    //     a[j + 1] = a[j];  // ���д���temp��Ԫ�ض�������
                    // }
                    // ����ѭ����a[j] <= temp �� j < 0���ʲ���λ��Ϊj+1
                    a[j + 1] = temp;
                }
            }
        }

        // ð������
        // ��ǰ����
        void bubble_sort1(int a[], int n) {
            for(int i = 0; i < n - 1; i++) {  // ����n-1��
                // ��i��ʱ��a[0]��a[n - i - 1]����������һ�����Ƚ�
                /* 
                    ����: a[10], a[0]~a[9]
                    ע����һ��a[0]��a[8]����Ҫ����һ�������бȽϣ��ڶ���a[0]��a[7]����Ҫ����һ�������бȽϣ�
                    �Դ����ƣ���i�˴�a[0]��a[n-i-1]����������һ�������бȽ�
                */
                for(int j = 0; j < n - i - 1; j++) {
                    if(a[j] > a[j + 1]) {  // �������������򽻻�
                        swap(a[j], a[j + 1]);
                    }
                }
            }
        }


        // �Ż����Ӻ���ǰ
        void bubble_sort2(int a[], int n) {
            for(int i = 0; i < n - 1; i++) {
                bool flag = false;  // ��ʾ�����Ƿ��������ı�־
                for(int j = n - 1; j > i; j--) {
                    if(a[j - 1] > a[j]) {  // ��߱��ұߴ��򽻻�
                        swap(a[j - 1], a[j]);
                        flag = true;
                    }
                }
                if(flag == false) 
                    return;  // ���˱�����û�з���������˵�����Ѿ�����
            }
        }

        // �鲢����
        // ����������a��[low, mid]��a[mid + 1, high]����ϲ�Ϊ��������
        void merge(int a[], int low, int mid, int high) {
            int i = low, j = mid + 1;  // iָ��a[low], jָ��a[high]
            int* temp = new int[high - low + 1];  // temp ��ʱ��źϲ��������
            int index = 0; // indexΪtemp�±�
            
            while (i <= mid && j <= high) {
                if(a[i] <= a[j]) {
                    temp[index++] = a[i++];
                } else {
                    temp[index++] = a[j++];
                }
            }

            while(i <= mid) temp[index++] = a[i++];  // ��[low, mid]��ʣ��Ԫ�ؼ�������temp
            while(j <= high) temp[index++] = a[j++];  // ��[mid + 1, high]��ʣ��Ԫ�ؼ�������temp
            
            for(int i = 0; i < index; i++) {
                a[low + i] = temp[i];  // ���ϲ�������и�ֵ������A 
            }
            
            delete[] temp;
        }


        void merge_sort(int a[], int low, int high) {
            if(low < high) {
                int mid = (low + high) / 2;  // ���м仮��
                merge_sort(a, low, mid);  // �ݹ飬����������[low, mid]�鲢����
                merge_sort(a, mid + 1, high); // �ݹ飬����������[mid + 1, high]�鲢����
                merge(a, low, mid, high);  // �������������������ϲ�
            }
        }


        int partition(int a[], int low, int high) {
            int pivot = a[low];  // �Ե�һ��Ԫ����Ϊ��׼
            while (low < high) {
                // ��highָ�벻�����ƣ�ֱ���ҵ��Ȼ�׼Ԫ��С��Ԫ��
                while(low < high && a[high] >= pivot) {
                    high--;
                }
                a[low] = a[high];  // �Ȼ�׼С��Ԫ���ƶ���lowָ���λ�� 
                // ��lowָ�벻�����ƣ�ֱ���ҵ��Ȼ�׼Ԫ�ش��Ԫ��
                while(low < high && a[low] <= pivot) {
                    low++;
                }
                a[high] = a[low]; // �Ȼ�׼С��Ԫ���ƶ���highָ���λ�� 
            }
            a[low] = pivot;  // ����׼Ԫ�طŵ�low��high�����ĵط�
            return low;
        }

        // �Ż�������һ�׼
        int partition_opt(int a[], int low, int high) {
            srand ((unsigned) time (NULL));
            int r = (round(1.0 * rand() / RAND_MAX * (high - low)) + low);
            swap(a[r], a[low]);  // ����a[r]��a[low]����a[r]Ϊ��׼ 
            int pivot = a[low];  // �Ե�һ��Ԫ����Ϊ��׼
            while (low < high) {
                // ��highָ�벻�����ƣ�ֱ���ҵ��Ȼ�׼Ԫ��С��Ԫ��
                while(low < high && a[high] >= pivot) {
                    high--;
                }
                a[low] = a[high];  // �Ȼ�׼С��Ԫ���ƶ���lowָ���λ�� 
                // ��lowָ�벻�����ƣ�ֱ���ҵ��Ȼ�׼Ԫ�ش��Ԫ��
                while(low < high && a[low] <= pivot) {
                    low++;
                }
                a[high] = a[low]; // �Ȼ�׼С��Ԫ���ƶ���highָ���λ�� 
            }
            a[low] = pivot;  // ����׼Ԫ�طŵ�low��high�����ĵط�
            return low;
        }

        void quick_sort(int a[], int low, int high) {
              if(low < high) {
                // �� [left, right] ��A[left]һ��Ϊ��(����)
                int pivot_pos = partition_opt(a, low, high);
                quick_sort(a, low, pivot_pos - 1);  // ����������ݹ���п�������
                quick_sort(a, pivot_pos + 1, high);  // ����������ݹ���п�������
              }

        }


        // ��ʾ�����Ľ��
        void sort_show(int a[], int n) {
            for(int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
        }

};

int main() {

    int a[N] = {71, 65, 16, 81, 92, 68, 31, 66, 99, 26};

    Sort sort;

    // sort.selection_sort(a, N);
    // sort.insert_sort(a, N);
    sort.bubble_sort1(a, N);
    // sort.bubble_sort2(a, N);
    // sort.merge_sort(a, 0, 9);
    // sort.quick_sort(a, 0, 9);
    sort.sort_show(a, N);



    return 0;
}

