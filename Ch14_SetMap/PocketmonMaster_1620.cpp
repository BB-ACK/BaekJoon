#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int included, test; 
    cin >> included >> test;
    map<string, int> poketmon; // 숫자로 찾을 수 있도록
    vector<string> arr; // 문자로 찾을 수 있도록록

    // 등록
    for(int i = 1; i <= included; i++) {
        string name; cin >> name;
        poketmon.insert({name, i});
        arr.push_back(name);
    }

    while(test--) {
       string find; cin >> find;
       int key;
       try {
        key = stoi(find);
        cout << arr[key-1] << '\n';
       } catch(invalid_argument) {
            cout << poketmon[find] << '\n';
        } 

    }
    return 0;
}