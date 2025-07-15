#include <iostream>
using namespace std;

long long newOperator(int a, int b) {
    long long left = a+b;
    long long right = a-b;

    return left*right;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << newOperator(a, b);
    return 0;
}