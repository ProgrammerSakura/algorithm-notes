#include <iostream>

using namespace std;


struct Node{
    int data;
    struct Node* next;
    
    //构造函数
    Node(int _data) : data(_data), next(NULL) {};
    Node() {};
};


int main() {
    
    Node node = Node();  // 定义一个结构体变量
    Node* LNode = &node;  // 定义一个指向结构体的指针
    
    // new Node()返回的是结构体起始地址，类似于C语言中的malloc函数
    Node* p = new Node(1);  // 等价于将上面两个步骤合并(生成一个结构体，再将这个结构体的地址用p指向)
    Node* p1 = new Node(2);
    Node* p2 = new Node(3);
    
    p->next = p1;
    p1->next = p2;
    
    // 头结点：第一个结点之前的结点，只存放链表第一个结点的地址，不存放值。
    
    
    // 变量用点调用，指针用->调用
    p->data = 1;
    node.data = 2;
    
//    cout << p->data;
//    cout << node.data << endl;
    

    // Node* head = p;  // head直接指向p,无头结点
    // 创建头结点
    Node* head = new Node();
    head->next = p;
    
    
    // 添加一个结点u
    Node* u = new Node(4);
    u->next = head->next;
    head->next = u;
    
    
    
    
    Node* L = head->next; // 从第一个结点开始 
    Node* pre = head;  // pre始终保存p的前驱结点的指针
    // 删除一个data=2的结点
    while(L != NULL) {
        if(L->data == 2) {
            pre->next = L->next;
            delete(L);
            L = pre->next;
        } else {  // data不为x，把pre和p都后移一位 
        	pre = L;
        	L = L->next;
        }
    }
    
    
    L = head->next; // 从第一个结点开始 
    // 遍历链表
    while(L != NULL) {
        cout << L->data << ' ';
        L = L->next;
    }

    Node p_test = *head;  // 等价于 Node* p_test = head;

    cout << p_test.next->next->data;
    cout << (*head).next->next->data;
    cout << head->next->next->data;

    return 0;
}