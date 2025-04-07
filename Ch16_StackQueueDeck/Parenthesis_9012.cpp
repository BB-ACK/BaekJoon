#include <iostream>
#include <stack>
#include <string>
using namespace std;

string VPS(string paren) {
    stack<char> tmp;

    for(int i = 0; i < paren.length(); i++) {
        if(paren[i] == ')' && !tmp.empty() && tmp.top() != ')') {
            tmp.pop();
        }
        else {
            tmp.push(paren[i]);
        }
    }

    if(tmp.empty())
        return "YES";
    else 
        return "NO";
}

int main() {
    int test; cin >> test;

    while(test--) {
       string paren; cin >> paren;

        cout << VPS(paren) << endl;
    }

    return 0;
}