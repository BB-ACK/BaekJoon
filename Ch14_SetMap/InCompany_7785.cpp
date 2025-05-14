#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int log; cin >> log;
    set<string> people;

    while(log--) {
        string name; cin >> name;
        string cmd; cin >> cmd;

        if(cmd == "enter") {
            people.insert(name);
        }
        else {
            people.erase(people.find(name));
        }
    }

    for(auto it = people.rbegin(); it != people.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}