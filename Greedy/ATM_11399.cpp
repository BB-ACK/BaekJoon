#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 사람 수 입력
    int people; cin >> people;
    vector<int> arr;

    // 인출 시간 입력
    for(int i = 0; i < people; i++) {
        int time; cin >> time;
        arr.push_back(time);
    }

    sort(arr.begin(), arr.end());

    int totalTime = 0;
    for(int i = people; i > 0; i--) {
        totalTime += i * arr[people-i];
    }

    cout << totalTime;
    
    return 0;
}