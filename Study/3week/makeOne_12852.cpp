#include <iostream>
#include <vector>
using namespace std;

int count = 0; // 연산 횟수 카운트용

/*주어진 수를 1로 만드는 함수*/
void makeOne(vector<int> &arr) {
    // 현재 값은 마지막 원소 참조
    int current = arr.back();

    // base case
    if(current == 1)
        return;

    count++;
    // 세 가지 조건
    if(current % 3 == 0) 
        current /= 3;
    else if(current % 2 == 0 && (current-1) % 3 != 0)
        current /= 2;
    else
        current--;
    
    // 현재 값을 대입 후 재귀
    arr.push_back(current);
    return makeOne(arr);
}

int main() {
    int num; cin >> num;
    vector<int> arr;

    arr.push_back(num);
    makeOne(arr);
    
    // 결과 출력문
    cout << count << endl;
    for(vector<int>::size_type i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}