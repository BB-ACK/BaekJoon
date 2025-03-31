#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num; cin >> num;
    vector<int> arr(num);

    // 대입
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    
    // 증가 부분 판정 및 카운트
    bool increase = true;
    int count = 1;

    for(int i = 1; i < num; i++) {
        if(increase == true && arr[i] > arr[i-1])
            count++;
        else if(arr[i] < arr[i-1]) {
            continue;
            increase = false;
        }
    }

    cout << count;
    
    return 0;
}