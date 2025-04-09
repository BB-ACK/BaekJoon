#include <iostream>
#include <queue>
using namespace std;

int shuffle(queue<int> card) {
    while(card.size() != 1) {
        card.pop(); // 먼저 버림
        card.push(card.front()); // 뒤로 넣고
        card.pop(); // 빼버림
    }

    return card.front();
}

int main() {
    int num; cin >> num;
    queue<int> card;

    for(int i = 1; i <= num; i++) {
        card.push(i);
    }

    cout << shuffle(card) << endl;
    
    return 0;
}