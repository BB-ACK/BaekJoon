#include <iostream>
using namespace std;

long long rFac(int num) {
    // base case
    if(num <= 1)
        return 1;

    return num * rFac(num-1);
}

int main() {
    int num; cin >> num;

    cout << rFac(num);

    return 0;
}