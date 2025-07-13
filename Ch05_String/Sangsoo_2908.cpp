#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int reverse(string &num1, string &num2) {
    int n1 = 0, n2 = 0;

    for(int i = 2; i >= 0; i--) {
        int tmp1 = num1[i] - '0';
        int tmp2 = num2[i] - '0';

        n1 += tmp1 * pow(10, i);
        n2 += tmp2 * pow(10, i);
    }

    if(n1 > n2)
        return n1;
    return n2;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    cout << reverse(num1, num2);
    
    return 0;
}