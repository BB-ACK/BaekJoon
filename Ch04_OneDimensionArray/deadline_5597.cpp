#include <iostream>
using namespace std;

int main() {
    int arr[30];

    // 배열 채우기
    for(int i = 0; i < 30; i++)
        arr[i] = i+1;

    // 제출자 배열에서 제외하기
    for(int i = 0; i < 28; i++) {
        int submit;
        cin >> submit;

        arr[submit-1] = 0;
    }

    // 제출하지 않은 번호 출력
    for(int i = 0; i < 30; i++) {
        if(arr[i] != 0)
            cout << i+1 << endl;
    }

    return 0;
}