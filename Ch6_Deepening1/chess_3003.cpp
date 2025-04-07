#include <iostream>
using namespace std;

int main() {
    int king;
    int queen;
    int look;
    int shoop;
    int knight;
    int phone;

    cin >> king >> queen >> look >> shoop >> knight >> phone;
    cout << 1 - king << " " << 1 - queen << " " << 2 -look << " " << 2 - shoop << " " << 2 -knight << " " << 8 - phone << endl;

    return 0;
}