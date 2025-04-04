#include <iostream>
#include <string>
using namespace std;

void findFraction(int num) {
    int mom = 1, son = 1;
    int find = 1;
    int increse = 1;

    // 분모를 늘려 범위를 좁힘
    while(find + increse <= num) {
        find += increse;
        increse++;
        mom++;
    }
    
    while(find != num) {
        find++;
        mom--;
        son++;
    }

    cout << to_string(son) + "/" + to_string(mom);
}

int main() {
    int num; cin >> num;

    findFraction(num);

    return 0;
}