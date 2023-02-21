#include <iostream>

using namespace std;

int f(int x, int y) {
    return (x % y + 1);
}

int main() {
    int a = 10, b = 4, c = 5;
    int k = f(f(a + c, b), f(b, c));
    printf("%d", k);
}