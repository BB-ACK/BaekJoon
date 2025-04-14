#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int queueStack(deque<int> &dq, int element) {
    dq.push_front(element);
    int nextElement = dq.back();
    dq.pop_back();

    return nextElement;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num; cin >> num;
    deque<int> dq;
    vector<int> qs;

    // 자료구조 타입 설정
    for(int i = 0; i < num; i++) {
        int ds; cin >> ds; 
        qs.push_back(ds);
    }

    // 원소대입
    for(int i = 0; i < num; i++) {
        int element; cin >> element;
        if(qs[i] == 0)
            dq.push_back(element);
    }

    // 대입할 수열
    int len; cin >> len;
    while(len--) {
        int push; cin >> push;
        cout << queueStack(dq, push) << " ";
    }


    return 0;
}