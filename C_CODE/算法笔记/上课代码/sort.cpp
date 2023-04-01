#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<ctime>
#include<cmath>

using namespace std;

const int N = 10;

class Sort {

    // 选择排序
    /*
        每次从序列中选择最小的元素
    */
    public: 
        void selection_sort(int a[], int n) {
            for(int i = 0; i < n; i++) {
                int k = i;
                // 选出[i, n-1]中最小的元素，下标为k
                for(int j = i; j < n; j++) {
                    if(a[k] > a[j]) {
                        k = j;
                    }
                }
                // 交换a[k]与a[i]
                swap(a[k], a[i]);
            }
        }

        // 从后面插入元素到前面以排好序的序列中。
        void insert_sort(int a[], int n) {
            for(int i = 1; i < n; i++) {  // 从第二个元素开始
                if(a[i] < a[i - 1]) {
                    int temp = a[i];  // temp暂存a[i]
                    int j = i - 1;  // 从i - 1开始往前枚举
                    while(j >= 0 && temp < a[j]) {  // 只要temp小于当前元素
                        a[j + 1] = a[j];  // 所有大于temp的元素都往后移
                        j--;
                    }
                    // for (int j = i - 1; j >= 0 && a[j] > temp; j--) {
                    //     a[j + 1] = a[j];  // 所有大于temp的元素都往后移
                    // }
                    // 跳出循环后a[j] <= temp 或 j < 0，故插入位置为j+1
                    a[j + 1] = temp;
                }
            }
        }

        // 冒泡排序
        // 从前往后
        void bubble_sort1(int a[], int n) {
            for(int i = 0; i < n - 1; i++) {  // 进行n-1趟
                // 第i趟时从a[0]到a[n - i - 1]都与它们下一个数比较
                /* 
                    例如: a[10], a[0]~a[9]
                    注：第一趟a[0]到a[8]都需要与下一个数进行比较，第二趟a[0]到a[7]都需要与下一个数进行比较，
                    以此类推，第i趟从a[0]到a[n-i-1]都与它们下一个数进行比较
                */
                for(int j = 0; j < n - i - 1; j++) {
                    if(a[j] > a[j + 1]) {  // 如果左边数更大，则交换
                        swap(a[j], a[j + 1]);
                    }
                }
            }
        }


        // 优化，从后往前
        void bubble_sort2(int a[], int n) {
            for(int i = 0; i < n - 1; i++) {
                bool flag = false;  // 表示本趟是否发生交换的标志
                for(int j = n - 1; j > i; j--) {
                    if(a[j - 1] > a[j]) {  // 左边比右边大则交换
                        swap(a[j - 1], a[j]);
                        flag = true;
                    }
                }
                if(flag == false) 
                    return;  // 本趟遍历后没有发生交换，说明表已经有序
            }
        }

        // 归并排序
        // 将有序序列a的[low, mid]和a[mid + 1, high]区间合并为有序区间
        void merge(int a[], int low, int mid, int high) {
            int i = low, j = mid + 1;  // i指向a[low], j指向a[high]
            int* temp = new int[high - low + 1];  // temp 临时存放合并后的数组
            int index = 0; // index为temp下标
            
            while (i <= mid && j <= high) {
                if(a[i] <= a[j]) {
                    temp[index++] = a[i++];
                } else {
                    temp[index++] = a[j++];
                }
            }

            while(i <= mid) temp[index++] = a[i++];  // 将[low, mid]的剩余元素加入序列temp
            while(j <= high) temp[index++] = a[j++];  // 将[mid + 1, high]的剩余元素加入序列temp
            
            for(int i = 0; i < index; i++) {
                a[low + i] = temp[i];  // 将合并后的序列赋值回数组A 
            }
            
            delete[] temp;
        }


        void merge_sort(int a[], int low, int high) {
            if(low < high) {
                int mid = (low + high) / 2;  // 从中间划分
                merge_sort(a, low, mid);  // 递归，将左子区间[low, mid]归并排序
                merge_sort(a, mid + 1, high); // 递归，将右子区间[mid + 1, high]归并排序
                merge(a, low, mid, high);  // 将左子区间和右子区间合并
            }
        }


        int partition(int a[], int low, int high) {
            int pivot = a[low];  // 以第一个元素作为基准
            while (low < high) {
                // 让high指针不断左移，直到找到比基准元素小的元素
                while(low < high && a[high] >= pivot) {
                    high--;
                }
                a[low] = a[high];  // 比基准小的元素移动到low指向的位置 
                // 让low指针不断右移，直到找到比基准元素大的元素
                while(low < high && a[low] <= pivot) {
                    low++;
                }
                a[high] = a[low]; // 比基准小的元素移动到high指向的位置 
            }
            a[low] = pivot;  // 将基准元素放到low与high相遇的地方
            return low;
        }

        // 优化，随机找基准
        int partition_opt(int a[], int low, int high) {
            srand ((unsigned) time (NULL));
            int r = (round(1.0 * rand() / RAND_MAX * (high - low)) + low);
            swap(a[r], a[low]);  // 交换a[r]与a[low]，以a[r]为基准 
            int pivot = a[low];  // 以第一个元素作为基准
            while (low < high) {
                // 让high指针不断坐移，直到找到比基准元素小的元素
                while(low < high && a[high] >= pivot) {
                    high--;
                }
                a[low] = a[high];  // 比基准小的元素移动到low指向的位置 
                // 让low指针不断右移，直到找到比基准元素大的元素
                while(low < high && a[low] <= pivot) {
                    low++;
                }
                a[high] = a[low]; // 比基准小的元素移动到high指向的位置 
            }
            a[low] = pivot;  // 将基准元素放到low与high相遇的地方
            return low;
        }

        void quick_sort(int a[], int low, int high) {
              if(low < high) {
                // 将 [left, right] 按A[left]一分为二(划分)
                int pivot_pos = partition_opt(a, low, high);
                quick_sort(a, low, pivot_pos - 1);  // 对左子区间递归进行快速排序
                quick_sort(a, pivot_pos + 1, high);  // 对右子区间递归进行快速排序
              }

        }


        // 显示排序后的结果
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

