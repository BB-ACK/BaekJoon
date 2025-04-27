#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

class AC {
private:
    deque<int> dq; // AC에 사용할 자료구조
    bool isReverse;  // 뒤집기 상태
    bool isError; // 에러 상태

public:
    // 생성자
    AC() {
        this->isReverse = false;
        this->isError = false;
    }

    // 원소 삽입 -> 처음 원소 삽입을 위한 함수
    void push(int e) {
        this->dq.push_back(e);
    }

    // 뒤집기
    void reverse() {
        if(this->isReverse) {
            this->isReverse = false;
            return;
        }
        this->isReverse = true;
    }

    // 삭제 함수
    void pop() {
        if(this->dq.empty()) {
            this->isError = true;
            return;
        }

        if(this->isReverse) { 
            dq.pop_back(); // 뒤집혀 있다면 뒤에서 뺌
        }
        else {
            dq.pop_front();
        }
    }

    // 출력문
    void print() {
        if(this->isError) {
            cout << "error" << '\n';
            return;
        }

        
        cout << '[';
        if(this->dq.empty()) {}
            // Do nothing
        else if(this->isReverse) {
            cout << this->dq.back();
            for(int i = this->dq.size() - 2; i >= 0; i--) {
                cout << ',' << this->dq[i];
            }
        }
        else {
            cout << this->dq.front();
            for (int i = 1; i < this->dq.size(); i++) {
                cout << ',' << this->dq[i];
            }
        }
        cout << ']' << '\n';
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test; cin >> test;

    while(test--) {
        AC ac;

        string cmd; cin >> cmd; // 예제의 RDD
        int elementNum; cin >> elementNum; // 예제의 4
        string array; cin >> array; // 예제의 [1,2,3,4]

        // 원소 파싱
        array = array.substr(1, array.size() - 2); // 대괄호 제거
        stringstream ss(array);
        string temp; 
        while(getline(ss, temp, ',')) {
            ac.push(stoi(temp));
        }
        
        
        // 명령어 실행 RD
        for(int i = 0; i < cmd.length(); i++) {
            char cur = cmd[i];

            if(cur == 'R') {
                ac.reverse();
            }
            else {
                ac.pop();
            }

        }
        
        ac.print();
    }
    
    return 0;
}