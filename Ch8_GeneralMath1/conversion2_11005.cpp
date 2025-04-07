#include <iostream>
#include <vector>
#include <string>
using namespace std;

void conversion(int num, int jin) {
    vector<char> arr; // 나머지 대입을 위한 백터

    while(num >= jin) {
        //10진수 이상인 경우
        if(num % jin >= 10) {
            arr.push_back(num % jin + 55); // 기본적으로 10의 값이 존재
        }
        else {
            arr.push_back(num % jin + '0');
        }
        num /= jin;
    }

    // 마지막 1번째 자리 추가가
    if(num >= 10) {
        arr.push_back(num + 55);
    }
    else {
        arr.push_back(num + '0');
    }

    // 출력문
    while(!arr.empty()) {
        cout << arr.back();
        arr.pop_back();
    }
    
}

int main() {
    int num, jin;
    cin >> num >> jin; // 10진수 N과 진법을 입력한다

    conversion(num, jin);

    return 0;  
}