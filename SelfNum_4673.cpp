#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(10001, 0); 

// n과 각 자리수를 더하는 함수
void functionD(int n) {
    int result = n;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }

    // 결과가 범위내이고 0이라면 -1표시 
    if(result <= 10000 && arr[result] == 0) 
        arr[result] = -1;
    
    // 10000보다 작은 경우 재귀를 통해 제거
    if(result < 10000)
        functionD(result);
}

int main() {
    // 출력 최적화
    ios::sync_with_stdio(false);
    cout.tie(0);

    for(int i = 1; i <= 10000; i++) {
        if(arr[i] == 0) {
            cout << i << '\n';
            functionD(i);
        }
    }


    return 0;
}