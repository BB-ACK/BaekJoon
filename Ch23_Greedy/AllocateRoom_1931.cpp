#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct lecture {
    int start;
    int end;
};

// 끝나는 시간순 오름차순 같다면 시작시간 기준 오름차순
bool cmp(lecture a, lecture b) {
    if(a.end == b.end)
        return a.start < b.start;
    else 
        return a.end < b.end;
}

int allocate(deque<lecture> &arr) {
    deque<lecture> allocated; // 배정된 강좌들
    allocated.push_back(arr.front());
    arr.pop_front();

    while(!arr.empty()) {
        lecture cur = arr.front();
        arr.pop_front();

        if(cur.start < allocated.back().end) {
            continue;
        }

        allocated.push_back(cur);

    }

    return allocated.size();
}

int main() {
    // 입력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lNum; cin >> lNum;
    deque<lecture> arr; // 강의들 배열 

    lecture lec;
    while(lNum--) {
        cin >> lec.start >> lec.end;
        arr.push_back(lec);
    }

    sort(arr.begin(), arr.end(), cmp); // 강의 정렬

    cout << allocate(arr);

    return 0;
}