#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    int count = 0;

    for(int i = 0; i < word.length(); i++) {
        if(word[i] == 'c' && word[i+1] == '=')
            count++;
        else if(word[i] == 'c' && word[i+1] == '-')
            count++;
        else if(word[i] == 'd' && word[i+1] == 'z' && word[i+2] == '=')
            count++;
        else if(word[i] == 'd' && word[i+1] == '-')
            count++;
        else if(word[i] == 'l' && word[i+1] == 'j')
            count++;
        else if(word[i] == 'n' && word[i+1] == 'j')
            count++;
        else if(word[i] == 's' && word[i+1] == '=')
            count++;
        else if(word[i] == 'z' && word[i+1] == '=')
            count++;
    }

    cout << word.length() - count;
    return 0;
}