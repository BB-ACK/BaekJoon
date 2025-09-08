#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;

    if (sum != 180) {
        cout << "Error" << endl;
    } else {
        if (a == 60 && b == 60 && c == 60) {
            cout << "Equilateral" << endl;
        } else if (a == b || b == c || a == c) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Scalene" << endl;
        }
    }

    return 0;
}
