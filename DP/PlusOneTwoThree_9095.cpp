#include <iostream>
#include <vector>
using namespace std;

int cases = 0; // 전역변수 경우의수

int count(int num) {

    // base case
    if(num == 0) {
        cases++;
        return cases;
    }

    if(num >= 3) 
        cases = count(num - 3);
    if(num >= 2)
        cases = count(num - 2);
    cases = count(num - 1);
    
    return cases;
}

int main() {
    int testCase; cin >> testCase;

    while(testCase--) {
        int num; cin >> num;
        cout << count(num) << '\n';
        cases = 0; // 전역변수 초기화
    }

    return 0;
}