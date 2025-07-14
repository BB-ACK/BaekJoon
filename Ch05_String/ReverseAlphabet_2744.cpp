#include <iostream>
#include <string>
#include <vector>
using namespace std;

void change(string word) {
    vector<char> result;

    for(int i = 0; i < word.length(); i++) {
        if(word[i] >= 'a') {
            result.push_back(word[i]-32);
        }
        else {
            result.push_back(word[i]+32);
        }
    }

    // 출력문
    for(int i = 0; i < result.size(); i++)
        cout << result[i];
}

int main() {
    string word; cin >> word;

    change(word);

    return 0;
}