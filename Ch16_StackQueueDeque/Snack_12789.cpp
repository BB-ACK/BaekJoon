#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

string isGetSnack(queue<int> order) {
    vector<int> space; // 한 명씩 설 수 있는 공간
    int cur = 1; // 현재 순서
    int orderSize = order.size(); // 변형이 되어 조건문에 사용을 위해

    for(int i = 0; i < orderSize; i++) {
        // 줄 서있는게 현재 번호인 경우
        if(order.front() == cur) {
            cur++;
            order.pop();
        }
        // 빈 공간에 서있는게 현재 번호인 경우
        else if(!space.empty() && space.back() == cur) {
            cur++;
            space.pop_back();
        }
        else {
            if (!space.empty() && space.back() < order.front()) {
                return "Sad";
            }
            space.push_back(order.front());
            order.pop();
        }
    }

    return "Nice";
}

int main() {
    int studentNum; cin >> studentNum;
    queue<int> order;

    while (studentNum--) {
        int num; cin >> num;
        order.push(num);    
    }

    cout << isGetSnack(order);
    
    return 0;
}