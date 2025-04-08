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
        if(order.front() == cur) {
            cur++;
            order.pop();
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

/*
오답 예제 
2 1 3 -> Nice
3 1 2 4 -> Nice
*/