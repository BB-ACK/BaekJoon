#include <iostream>
#include <vector>
using namespace std;

// 1을 만드는 함수
void makeOne(vector<int> &arr, int num, int ops) {
    // 더 좋은 경우가 있는 경우 스킵
    if(ops >= arr[num-1]) return;
    arr[num-1] = ops;
    
    // base case
    if(num == 1) return;


    // 3 or 2로 나뉘는 경우
    if(num % 3 == 0) {
        makeOne(arr, num/3, ops+1);
    }
    if(num % 2 == 0) {
        makeOne(arr, num/2, ops+1);
    }

    // -1의 경우도 포함
    makeOne(arr, num-1, ops+1);

};

int main() {
    // 입력값 N
    int num; cin >> num;
    vector<int> arr(num, INT32_MAX); // 최소 연산 횟수를 저장해놓을 배열

    makeOne(arr, num, 0);

    cout << arr[0];

    return 0;
}