#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> arr;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back({num, i});
    }

    // 정렬
    sort(arr.begin(), arr.end());

    int max_move = 0;
    for (int i = 0; i < n; i++) {
        max_move = max(max_move, arr[i].second - i);
    }

    cout << max_move + 1 << '\n';
    return 0;
}
