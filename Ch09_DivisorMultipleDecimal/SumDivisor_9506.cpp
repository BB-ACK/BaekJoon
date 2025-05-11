#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, int> findDivisor(int num) {
    pair<vector<int>, int> result;
    // 약수 구하기
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            result.first.push_back(i);
            result.second += i;
        }
    }


    return result;
} 


int main() {
    int num;

    while(1) {
        cin >> num;
        if(num == -1)
            break;
        
        pair<vector<int>, int> divisor = findDivisor(num);
        
        // 완전수인 경우
        if(divisor.second == num) {
            cout << num << " = " << divisor.first[0];
            for(int i = 1; i < divisor.first.size(); i++) {
                cout << " + " << divisor.first[i];
            }
        }
        else {
            cout << num << " is NOT perfect.";
        }
        
        cout << endl;
    }   

    return 0;
}