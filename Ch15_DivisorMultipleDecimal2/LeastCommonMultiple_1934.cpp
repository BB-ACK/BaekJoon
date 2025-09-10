#include <iostream>
using namespace std;

int GCD(int a, int b) {
    // base case 
    if(b == 0)
        return a;

    int tmp = a % b;
    return GCD(b, tmp);
}

int main() {
    int test; cin >> test;

    while(test--) {
        int a, b; cin >> a >> b;
        int gcd = GCD(a, b);

        int quotA = a / gcd;
        
        cout << b * quotA << '\n';
    }
    return 0;
}