#include <iostream>
#include <string>
using namespace std;

int score(string answer) {
    int sum = 0;
    int point = 1;

    for(int i = 0; i < answer.length(); i++) {
        if(answer[i] == 'O') {
            sum += point;
            point++;
        }
        else{
            point = 1;
        }
    }

    return sum;
}

int main() {
    int test; cin >> test;

    while(test--) {
        string answer; cin >> answer;
        cout << score(answer) << '\n';
    }
    
    return 0;
}