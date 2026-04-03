#include <iostream>
#include <vector>
using namespace std;

// 0과 1의 갯수 구조체
struct Count {
    int zero;
    int one;
};

pair<int, int> fibo(int num) {
    if(num == 0) return {1, 0};
    if(num == 1) return {0, 1};

    vector<Count> arr(num+1); // 0과 1의 출력 횟수 배열

    // 0, 1번째 초기화
    arr[0] = {1, 0};
    arr[1] = {0, 1};

    // dp방식
    for(int i = 2; i <= num; i++) {
        arr[i].zero = arr[i-1].zero + arr[i-2].zero;
        arr[i].one = arr[i-1].one + arr[i-2].one;
    }

    return {arr[num].zero, arr[num].one};
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase; cin >> testCase;

    while(testCase--) {
        int num; cin >> num;
        auto result = fibo(num);

        cout << result.first << " " << result.second << '\n';
    }
    
    return 0;
}