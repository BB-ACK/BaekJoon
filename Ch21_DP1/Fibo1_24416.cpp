#include <iostream>
#include <vector>
using namespace std;

// 재귀적 피보나치 함수
int rFibo(int n) {
    static int cnt = 1;
    // base case
    if(n <= 2) {
        return 1;
    }
    else {
        cnt++;
        int result = rFibo(n-1) + rFibo(n-2);
        return cnt;
    } 
        
}

// 동적 피보나치 함수
int dpFibo(int n) {
    int cnt = 0;
    vector<int> arr(n+1);
    arr[1] = 1; arr[2] = 1;

    for(int i = 3; i <= n; i++) {
        cnt++;
        arr[i] = arr[i-1] + arr[i-2];
    }

    return cnt;
}

int main() {
    int n; cin >> n;

    cout << rFibo(n) << " " << dpFibo(n);

    return 0;
}