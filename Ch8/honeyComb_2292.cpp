#include <iostream>
using namespace std;

int findRoot(int find) {
    int distance = 1, num = 1;
    int room = 6; // 늘어나는 방 수
    
    while(num < find) {
        num += room;
        room += 6;
        distance++;
    }

    return distance;
}

int main() {
    int find; cin >> find;

    cout << findRoot(find);
    
    return 0;
}