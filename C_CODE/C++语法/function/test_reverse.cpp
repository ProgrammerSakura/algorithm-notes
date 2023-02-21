#include <iostream>

using namespace std;

int main() {
    string str = "test reverse";
    // c.end();是一个迭代器，是个指针，前面加个*访问其中的内容。
    cout << *(str.end()-1) << endl; // e
    cout << (int)*(str.end()) << endl;  // 0

    return 0;
}