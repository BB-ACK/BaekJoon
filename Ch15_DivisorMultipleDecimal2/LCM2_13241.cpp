#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
    // base case
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    long long a, b;
    cin >> a >> b;

    int max = gcd(a, b);
    long long lcm = b / max;

    cout << a * lcm;
    
    return 0;
}