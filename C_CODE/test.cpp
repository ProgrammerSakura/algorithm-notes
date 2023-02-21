#include<iostream>
#include<cstdio>
#include<vector>
const int SIZE = 10;

using namespace std;

struct RT{
 int x;
 void xz();
};

template<size_t n>
struct NumAdd<n>{
    constexpr int num = NumAdd<n-1>::num+this->num; 
}
template<>
struct NumAdd<0>{
    const int num = 1;
}
class DisjointSets
{
private:
    int count = SIZE;  // ���鼯�м��ϸ���(���ĸ���)
    int set[SIZE];  // ������洢

public:
    DisjointSets(int count)
    {   
        this->count = count;
        for(int i = 0; i < count; i++) 
        {
            this->set[i] = -1;  // ��������ֵ��Ϊ-1
        }
    }
    ~DisjointSets(){};  // �������������������ʵ��ǰ����

    // ����������ҵ����ڵ��ٽ��С�·��ѹ����
    int find_sets(int x): noexcept const 
    {
        int root = x;
        while (this->set[root] >= 0)  // ѭ���ҵ���
        {
            root = this->set[root];  // ����Լ��ĸ��׽��
        }

        // ѹ��·������x�����ڵ�ľ��������н��ȫ���ҵ����ڵ���
        while (x != root)
        {
            int parent = this->set[x];  // ����x�ĸ��ڵ�
            this->set[x] = root;  // x�����������ֱ�ӹҵ����ڵ���
            x = parent;
        }

        return root; // ���ظ��ڵ���
    }

    void union_sets(int x, int y) 
    {
        // �ϲ�֮ǰ����Ҫ�ж���Ҫ�ϲ��������ڵ��Ƿ���ͬһ�����鼯������ͬһ�����ϣ�
        // �ֱ��ȡx����y����������ĸ��ڵ�
        int root_x = this->find_sets(x);
        int root_y = this->find_sets(y);

        if (root_x == root_y)
            return;  // ������ͬһ������

        if(this->set[root_x] > this->set[root_y])   // ��ʾroot_x���������
        {
            this->set[root_y] += set[root_x];  // �ۼӽ������
            this->set[root_x] = root_y;  // С���ϲ�������
        } else
        {
            this->set[root_x] += set[root_y];  // �ۼӽ������
            this->set[root_y] = root_x;  // С���ϲ�������
        }
        
        // ��ʱɭ���е�����һ
        this->count--;
    }

    int get_counts() 
    {
        return this->count;
    }

};


int main() 
{
    // ��ʼ�����鼯������������Ԫ��
    // DisjointSets union_find(SIZE);
    auto union_find = std::shared_ptr<DisjointSets>(SIZE);
    // ���ϲ��Ľ���    
    int node_union[5][2] = {{1, 2}, {1, 5}, {3, 4}, {5, 2}, {0, 3}};

    // �鿴�ϲ���ļ��ϸ���
    cout << "�ϲ�ǰ�ļ��ϸ���Ϊ��" << union_find.get_counts() << endl;

    cout << "===========��ʼ�ϲ�============" << endl;
    // �ϲ����
    for(int i = 0; i < 6; i++) {
        int node1 = node_union[i][0];
        int node2 = node_union[i][1];
        union_find.union_sets(node1, node2);
    }
    cout << "===========�ϲ�����============" << endl;

    for(int i = 0; i < SIZE; i++) {
        printf("���%d�ĸ����Ϊ��%d\n", i, union_find.find_sets(i));
    }

    // �鿴�ϲ���ļ��ϸ���
    cout << "�ϲ���ļ��ϸ���Ϊ��" << union_find.get_counts() << endl;

    return 0;
}


