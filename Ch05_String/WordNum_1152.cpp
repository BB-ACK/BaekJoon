#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    stringstream ss(sentence); // 공백을 기준으로 나눔
    string word;
    int count = 0;

    // 나눠진 단어를 하나씩 word에 저장, 존재하면 true로 카운트 증가
    while (ss >> word) { 
        count++;
    }

    cout << count;
    return 0;
}
