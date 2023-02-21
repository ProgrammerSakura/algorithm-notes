#include <iostream>

using namespace std;


struct Node{
    int data;
    struct Node* next;
    
    //���캯��
    Node(int _data) : data(_data), next(NULL) {};
    Node() {};
};


int main() {
    
    Node node = Node();  // ����һ���ṹ�����
    Node* LNode = &node;  // ����һ��ָ��ṹ���ָ��
    
    // new Node()���ص��ǽṹ����ʼ��ַ��������C�����е�malloc����
    Node* p = new Node(1);  // �ȼ��ڽ�������������ϲ�(����һ���ṹ�壬�ٽ�����ṹ��ĵ�ַ��pָ��)
    Node* p1 = new Node(2);
    Node* p2 = new Node(3);
    
    p->next = p1;
    p1->next = p2;
    
    // ͷ��㣺��һ�����֮ǰ�Ľ�㣬ֻ��������һ�����ĵ�ַ�������ֵ��
    
    
    // �����õ���ã�ָ����->����
    p->data = 1;
    node.data = 2;
    
//    cout << p->data;
//    cout << node.data << endl;
    

    // Node* head = p;  // headֱ��ָ��p,��ͷ���
    // ����ͷ���
    Node* head = new Node();
    head->next = p;
    
    
    // ���һ�����u
    Node* u = new Node(4);
    u->next = head->next;
    head->next = u;
    
    
    
    
    Node* L = head->next; // �ӵ�һ����㿪ʼ 
    Node* pre = head;  // preʼ�ձ���p��ǰ������ָ��
    // ɾ��һ��data=2�Ľ��
    while(L != NULL) {
        if(L->data == 2) {
            pre->next = L->next;
            delete(L);
            L = pre->next;
        } else {  // data��Ϊx����pre��p������һλ 
        	pre = L;
        	L = L->next;
        }
    }
    
    
    L = head->next; // �ӵ�һ����㿪ʼ 
    // ��������
    while(L != NULL) {
        cout << L->data << ' ';
        L = L->next;
    }

    Node p_test = *head;  // �ȼ��� Node* p_test = head;

    cout << p_test.next->next->data;
    cout << (*head).next->next->data;
    cout << head->next->next->data;

    return 0;
}