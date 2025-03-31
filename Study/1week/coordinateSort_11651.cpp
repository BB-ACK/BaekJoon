#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
};

// 비교 조건 
bool compare(coordinate a, coordinate b) {
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num; cin >> num;
    vector<coordinate> arr;

    for(int i = 0; i < num; i++) {
        coordinate cor;
        cin >> cor.x >> cor.y;

        arr.push_back(cor);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < num; i++)
        cout << arr[i].x << " " << arr[i].y << "\n";

    return 0;
}