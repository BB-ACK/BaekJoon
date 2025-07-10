#include <iostream>
#include <string>
using namespace std;

int main() {
    int test; cin >> test;

    for(int i = 1; i <= test; i++) {
        int a, b; cin >> a >> b;

        cout << "Case #" << i << ": ";
        cout << a << " + " << b << " = " << a+b;
        cout << '\n';
    }

    return 0;
}