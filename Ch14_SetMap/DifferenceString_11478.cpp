#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string word; cin >> word;
    set<string> arr;

    for(int i = 0; i < word.length(); i++) {
        for(int j = 1; j <= word.length() - i; j++) {
            arr.insert(word.substr(i, j));
        }
    }

    cout << arr.size();
    return 0;
}