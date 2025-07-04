#include <iostream>
#include <string>
#include <deque>
using namespace std;

// 문자열에서 폭발문자열을 폭발하는 함수
void boom(deque<char> &arr, string boomWord) {
    deque<char> result; 

}

int main() {
    deque<char> arr;

    string word; cin >> word;
    string boomWord; cin >> boomWord;
    for(int i = 0; i < word.length(); i++) {
        arr.push_back(word[i]);
    }

    return 0;
}