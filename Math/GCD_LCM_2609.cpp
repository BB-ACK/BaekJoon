#include <iostream>
using namespace std;

int GCD(int n1, int n2) {
    // base case
    if(n2 == 0) 
        return n1;
    
    return GCD(n2, n1 % n2);
}

int main() {
    int n1, n2; cin >> n1 >> n2;

    int gcd = GCD(n1, n2);
    int mul = n1 / gcd;
    int lcm = n2 * mul;

    cout << gcd << '\n' << lcm;

    return 0;
}