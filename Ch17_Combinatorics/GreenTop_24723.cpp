#include <iostream>
using namespace std;

int twoFactorial(int n) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= 2;
    }

    return result;
}

int main() {
    int floor; cin >> floor;

    cout << twoFactorial(floor);

    return 0;
}