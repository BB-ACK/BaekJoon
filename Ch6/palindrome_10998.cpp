#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;

    cin >> word;

    string temp(word.length(), ' ');
    int count = 0;
    for(int i = 0; i < word.length(); i++)       
        temp[i] = word[word.length() - i - 1];
    

    for(int i = 0; i < word.length(); i++) 
        if(word[i] == temp[i])
            count++;

    if(count == word.length())
        cout << 1;
    else
        cout << 0;
    return 0;
}