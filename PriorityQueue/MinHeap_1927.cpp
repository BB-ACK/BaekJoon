#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> arr;

public:
    // 생성자

    int isEmpty() {
        return this->arr.size() == 0;
    }

    // 우선순위를 정하기 위해
    int findMinIdx() {
        long long min = INT32_MAX;
        int idx = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < min) {
                min = arr[i];
                idx = i;
            }
        }

        return idx;
    }

    // 정수가 입력됐을 때
    void push(int element) {
        arr.push_back(element);
    }

    // 0이 입력됐을 때
    void pop() {
        if(this->isEmpty()) {
            cout << 0 << '\n';
            return;
        }
        
        int idx = this->findMinIdx();
        cout << arr[idx] << "\n";
        arr.erase(arr.begin() + idx);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test; cin >> test;
    PriorityQueue pq;

    while(test--) {
        int cmd; cin >> cmd;

        switch (cmd){
        case 0:
            pq.pop();
            break;
        default:
            pq.push(cmd);
            break;
        }
    }
    return 0;
}