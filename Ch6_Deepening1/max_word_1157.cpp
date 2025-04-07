#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    int repeat[126] = {0};

    // 문자열 빈도를 계산한다
    for(int i = 0; i < word.length(); i++) {
        if(int(word[i]) >= 97)
            repeat[int(word[i]-32)]++;
        else
            repeat[int(word[i])]++;
    }    

    int maxFre = 0;
    char mostword = 0;

    // 최대로 많이 반복된 값을 구한다
    for(int i = 0; i < 126; i++) {
        if(repeat[i] > maxFre) {
            maxFre = repeat[i];
            mostword = char(i);
        }
        else if(repeat[i] == maxFre) {
            maxFre = repeat[i];
            mostword = '?';
        }
    }

    cout << mostword;
    return 0;
}