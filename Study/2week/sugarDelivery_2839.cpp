#include <iostream>
#include <vector>
using namespace std;

int kg[2] = {5,3};

int delivery(vector<int> &arr, int sugar) {
    // 배열 초기화
    for(int i = 0; i <= sugar; i++) {
        arr[i] = -1;
    }
    // 초기값
    arr[3] = 1;
    arr[5] = 1;
    
    // 입력받은 설탕 양까지 bottom-up
    for(int current = 5; current <= sugar; current++) {
        // 2가지 종류 반복
        for(int kind = 0; kind < 2; kind++) {
            if(arr[current - kg[kind]] > 0) {
                arr[current] = arr[current - kg[kind]] + 1;
                break; // 그리디이기에 5가 먼저면 끝냄
            }
        }        
    }

    return arr[sugar];
}

int main() {
    int sugar; cin >> sugar;
    vector<int> arr(sugar+1);

    cout << delivery(arr, sugar) << endl;

    return 0;
}