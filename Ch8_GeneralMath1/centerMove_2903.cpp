#include <iostream>
using namespace std;

// 점의 갯수를 세는 함수
int findPointNum(int num) {    
    int pointNum = 1;
    
    while(num--) {
        pointNum *= 2;
    }

    return (pointNum + 1)  * (pointNum + 1);
}

int main() {
    int num; cin >> num;

    cout << findPointNum(num);

    return 0;
}

/*
    4
    9 : +5 4 * 4 -
    25: + 16
    
*/