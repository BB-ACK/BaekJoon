// 이항계수를 구하는 문제
#include <iostream>
using namespace std;

int binom(int n, int k) {
    int sum = 1;
    int tmp = 1;
    for(int i = 0; i < k; i++) {
        sum *= n-i;
        tmp *= i+1;
    }

    return sum / tmp;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << binom(n, k);

    return 0;
}