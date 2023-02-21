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
    int count = SIZE;  // 并查集中集合个数(树的个数)
    int set[SIZE];  // 用数组存储

public:
    DisjointSets(int count)
    {   
        this->count = count;
        for(int i = 0; i < count; i++) 
        {
            this->set[i] = -1;  // 将根结点的值设为-1
        }
    }
    ~DisjointSets(){};  // 类的析构函数，销毁类实例前调用

    // 查操作，先找到根节点再进行“路径压缩”
    int find_sets(int x): noexcept const 
    {
        int root = x;
        while (this->set[root] >= 0)  // 循环找到根
        {
            root = this->set[root];  // 获得自己的父亲结点
        }

        // 压缩路径，将x到根节点的经过的所有结点全部挂到根节点下
        while (x != root)
        {
            int parent = this->set[x];  // 保存x的父节点
            this->set[x] = root;  // x结点所在子树直接挂到根节点下
            x = parent;
        }

        return root; // 返回根节点编号
    }

    void union_sets(int x, int y) 
    {
        // 合并之前还需要判断需要合并的两个节点是否是同一个并查集分量（同一棵树上）
        // 分别获取x结点和y结点所属树的根节点
        int root_x = this->find_sets(x);
        int root_y = this->find_sets(y);

        if (root_x == root_y)
            return;  // 表明在同一棵树中

        if(this->set[root_x] > this->set[root_y])   // 表示root_x结点数更少
        {
            this->set[root_y] += set[root_x];  // 累加结点总数
            this->set[root_x] = root_y;  // 小树合并到大树
        } else
        {
            this->set[root_x] += set[root_y];  // 累加结点总数
            this->set[root_y] = root_x;  // 小树合并到大树
        }
        
        // 此时森林中的树减一
        this->count--;
    }

    int get_counts() 
    {
        return this->count;
    }

};


int main() 
{
    // 初始化并查集，其中有六个元素
    // DisjointSets union_find(SIZE);
    auto union_find = std::shared_ptr<DisjointSets>(SIZE);
    // 待合并的结点对    
    int node_union[5][2] = {{1, 2}, {1, 5}, {3, 4}, {5, 2}, {0, 3}};

    // 查看合并后的集合个数
    cout << "合并前的集合个数为：" << union_find.get_counts() << endl;

    cout << "===========开始合并============" << endl;
    // 合并结点
    for(int i = 0; i < 6; i++) {
        int node1 = node_union[i][0];
        int node2 = node_union[i][1];
        union_find.union_sets(node1, node2);
    }
    cout << "===========合并结束============" << endl;

    for(int i = 0; i < SIZE; i++) {
        printf("结点%d的根结点为：%d\n", i, union_find.find_sets(i));
    }

    // 查看合并后的集合个数
    cout << "合并后的集合个数为：" << union_find.get_counts() << endl;

    return 0;
}


