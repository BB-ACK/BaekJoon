#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

struct lecture {
    int start;
    int end;
};

struct cmp {
    bool operator() (lecture a, lecture b) {
        if(a.start == b.start)
            return a.end > b.end;
        else
            return a.start > b.start;
    }
};

// 필요한 강의실의 갯수를 찾는 함수
int allocated(priority_queue<lecture, vector<lecture>, cmp> &lectures) {
    priority_queue<int, vector<int>, greater<int>> lectureEnd; // 수업의 끝난 시간 저장 -> 강의실 갯수

    while(!lectures.empty()) {
        lecture top = lectures.top();
        
        // 처음 접근시 강의실 목록 생성
        if(lectureEnd.empty()) {
            lectureEnd.push(top.end);
            lectures.pop();
            continue;    
        }

        // 가장 빠른 수업이 끝나기 전에 시작하는 경우 -> 새로운 강의실 추가
        if(top.start < lectureEnd.top()) {
            lectureEnd.push(top.end);
            lectures.pop();
        }
        // 가장 빠른 수업이 끝나고 시작하는 경우 -> 강의실 시간 조정 : 추가 x
        else {
            lectureEnd.pop();
            lectureEnd.push(top.end);
            lectures.pop();
        }

    }

    return lectureEnd.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<lecture, vector<lecture>, cmp> lectures;

    int num; cin >> num;
    while(num--) {
        lecture lec;
        cin >> lec.start >> lec.end;
        lectures.push(lec);
    }

    cout << allocated(lectures);

    return 0;
}