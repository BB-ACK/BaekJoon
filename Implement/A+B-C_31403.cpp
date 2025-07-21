#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    cout << stoi(a) + stoi(b) - stoi(c) << '\n';

    int num = stoi(a+b);
    cout << num - stoi(c);
    
    return 0;
}