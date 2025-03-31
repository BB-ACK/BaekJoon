#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct study {
    int start;
    int end;
};

// 끝나는 시간이 느린 순서로 정렬
bool compare(study a, study b) {
    return a.end > b.end;
}

int assign(vector<study> &arr, int num) {
    int endTime, fastStart = arr[num].end;
    arr.pop_back(); num--;

    // base case
    if(num == 0) {
        return 1;
    }
    
    // 가장 짧은 시작 시간 찾기
    for(int i = 0; i < num; i++) {
        if(arr[i].start );
    }

}

int main() {
    int num; cin >> num;
    vector<study> arr(num);

    for(int i = 0; i < num; i++) {
        cin >> arr[i].start >> arr[i].end;
    }

    // 끝나는 시간 순 정렬
    sort(arr.begin(), arr.end(), compare);


    return 0;
}