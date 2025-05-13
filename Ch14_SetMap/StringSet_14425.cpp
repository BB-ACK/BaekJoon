#include <iostream>
#include <string>
#include <set>
using namespace std;

int countString(set<string> &arr, multiset<string> &search) {
    int count = 0;

    for(set<string>::iterator it = search.begin(); it != search.end(); it++) {
        if(arr.find(*it) == arr.end())
            continue;
        count++;    
    }

    return count;
}

int main() {
    int N, M;
    cin >> N >> M;

    set<string> arr;
    multiset<string> search;

    while(N--) {
        string str; cin >> str;
        arr.insert(str);
    }

    while(M--) {
        string str; cin >> str;
        search.insert(str);
    }

    cout << countString(arr, search);

    return 0;
}