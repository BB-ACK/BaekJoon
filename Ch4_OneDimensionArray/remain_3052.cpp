#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int count = 0;

    // 배열의 값 초기화    
    for(int i = 0; i < 10; i++) 
        arr[i] = -1;

    // 나머지 값 대입
    for(int i = 0; i < 10; i++) {
        int a;
        cin >> a;
        int temp = a % 42;

        // 나머지가 기존의 없는 경우만 값을 증가
        for(int j = 0; j <= i; j++) {
            if(arr[j] == temp)
                break;
            
            if(j == i) {
                arr[i] = temp;
                count++;
            }
        
        }
    }
    cout << count;
    
    return 0;
}