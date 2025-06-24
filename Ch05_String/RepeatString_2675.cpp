#include <iostream>
#include <string>
using namespace std;

int main() {
    int test; cin >> test;

    while(test--) {
        int num; cin >> num;
        string word; cin >> word;

        for(int i = 0; i < word.length(); i++) {
            for(int j = 0; j < num; j++) {
                cout << word[i];
            }
        }

        cout << '\n';
    }

    return 0;
}