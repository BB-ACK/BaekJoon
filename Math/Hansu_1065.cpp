#include <iostream>
#include <vector>
using namespace std;

int Hansu(int num) {
    // 100이하는 무조건 한수처리
    if(num < 100) return num;

    int result = 99; // 100보다 큰 경우 기본 한수 갯수

    for(int i = 100; i <= num; i++) {
        vector<int> arr;
        int cur = i;

        // 각 자릿수 배열의 삽입
        while(cur > 0) {
            int remain = cur % 10;
            cur /= 10;
            
            arr.push_back(remain);
        }

        int diffrence = arr[0] - arr[1]; // 등차
        bool isHansu = true;
        for(int j = 1; j < arr.size()-1; j++) {
            if(arr[j] - arr[j+1] != diffrence) {
                isHansu = false;
                break;
            }
        }

        if(isHansu) result++;
    }

    return result;
}

int main() {
    int num; cin >> num;

    cout << Hansu(num);

    return 0;
}