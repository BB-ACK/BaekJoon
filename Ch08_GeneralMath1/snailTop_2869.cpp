#include <iostream>
using namespace std;

int ontheTop(int up, int down, int top) {
    return ((top - down - 1) / (up - down)) + 1;
}

int main() {
    int up, down, top;
    cin >> up >> down >> top;

    cout << ontheTop(up, down, top);

    return 0;
}