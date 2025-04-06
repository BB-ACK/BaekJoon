#include <iostream>
#include <string>
using namespace std;

void findFraction(int num) {
    int line = 1, find = 0;

    while(find < num) {
        find += line;
        line++;
    }

    line--; // 실제 줄 번호
    int index = num - (find - line); // 몇 번째 인덱스인지
    int son, mom;

    if(line % 2) { // 홀수 줄 방향
        mom = index;
        son = line - index + 1;
    }
    else {
        mom = line - index + 1;
        son = index;
    }

    cout << son << "/" << mom;
}

int main() {
    int num; cin >> num;

    findFraction(num);

    return 0;
}