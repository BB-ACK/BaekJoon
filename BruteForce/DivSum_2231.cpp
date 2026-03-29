#include <iostream>
using namespace std;

// num에 각 자릿수를 더하는 함수
int functionD(int num) {
    int sum = num;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    int num; cin >> num;
    bool find = false;
    for(int i = 0; i < num; i++) {
        int result = functionD(i);
        
        // 생성자를 찾은 경우 출력 후 종료
        if(result == num) {
            cout << i;
            find = true;
            break;
        }
    }

    if(find == false) cout << 0;
    

    return 0;
}