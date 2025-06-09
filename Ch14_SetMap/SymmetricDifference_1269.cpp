#include <iostream>
#include <set>
using namespace std;

int dif(set<int> a, set<int> b) {
    int aCnt = 0, bCnt = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        if(b.find(*it) != b.end()) 
            aCnt++;
    }

    for(auto it = b.begin(); it != b.end(); it++) {
        if (a.find(*it) != a.end())
            bCnt++;
    }

    return a.size() - aCnt + b.size() - bCnt;
}

int main() {
    int aNum, bNum;
    cin >> aNum >> bNum;

    set<int> arr1;
    set<int> arr2;

    for(int i = 0; i < aNum; i++) {
        int e; cin >> e;
        arr1.insert(e);
    }

    for (int i = 0; i < bNum; i++) {
        int e; cin >> e;
        arr2.insert(e);
    }

    cout << dif(arr1, arr2);

    return 0;
}