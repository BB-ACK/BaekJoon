#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findAlphabet(string word) {
    int count = 0;
    vector<int> result(26, -1); // -1 초기화

    for(int i = 0; i < word.length(); i++) {
        int idx = word[i] - 'a';
        
        if(result[idx] == -1)
            result[idx] = i;
    }

    // 출력문 
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

int main() {
    string word; cin >> word;

    findAlphabet(word);
    
    return 0;
}