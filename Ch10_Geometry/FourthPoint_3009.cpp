#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
};

int main() {
    vector<coordinate> arr(4);

    for(int i = 0; i < 3; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    // x좌표 출력
    if(arr[0].x == arr[1].x)
        cout << arr[2].x << " ";
    else if(arr[0].x == arr[2].x)
        cout << arr[1].x << " ";
    else {
        cout << arr[0].x << " ";
    }

    // y좌표 출력
    if (arr[0].y == arr[1].y)
        cout << arr[2].y;
    else if (arr[0].y == arr[2].y)
        cout << arr[1].y;
    else {
        cout << arr[0].y;
    }

    return 0;
}