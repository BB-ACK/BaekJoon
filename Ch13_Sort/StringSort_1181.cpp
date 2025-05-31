#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        return a < b;
    }
}

int main() {
    int num; cin >> num;
    set<string> arr;

    while(num--) {
        string word; cin >> word;
        arr.insert(word);
    }

    vector<string> vec(arr.begin(), arr.end()); // set으로 자동으로 중복 제거

    sort(vec.begin(), vec.end(), cmp);

    for(const string &s : vec)
        cout << s << '\n';
    return 0;
}