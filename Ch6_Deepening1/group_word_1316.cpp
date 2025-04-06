#include <iostream>
#include <string>
using namespace std;

int main() {
    int test;
    cin >> test;

    string word;
    int count= 0;

    // 여러개의 단어를 입력받기
    while(test--) {
        cin >> word;

        // 단어가 그룹적인지 체크
        for(int i = 0; i < word.length(); i++) {
            int find = word.find(word[i], i+1);
            // cout << i << " " << find << endl;
            
            // 단어가 연속일 경우 단어가 연속이 아닐 때까지 반복
            if(find == i+1) {
                while(word[i] != word[i+1])
                    i++;
            }
            else if(find != -1)
                break;
            
            if(i == word.length() - 1)
                count++;
        }    
    }

    cout << count;
    return 0;
}