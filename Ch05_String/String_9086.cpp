#include <iostream>
#include <string>
using namespace std;

int main() {
    int test; cin >> test;

    while(test--) {
        string word; cin >> word;
        cout << word[0] << word[word.length()-1] << '\n';
    }

    return 0;
}