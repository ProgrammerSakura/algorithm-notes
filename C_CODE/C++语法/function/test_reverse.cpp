#include <iostream>

using namespace std;

int main() {
    string str = "test reverse";
    // c.end();��һ�����������Ǹ�ָ�룬ǰ��Ӹ�*�������е����ݡ�
    cout << *(str.end()-1) << endl; // e
    cout << (int)*(str.end()) << endl;  // 0

    return 0;
}