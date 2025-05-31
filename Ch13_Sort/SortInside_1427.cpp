#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

int main() {
    string num; cin >> num;
    vector<int> arr;
    for(int i = 0; i < num.length(); i++) {
        arr.push_back(num[i] - '0');
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
    return 0;
}