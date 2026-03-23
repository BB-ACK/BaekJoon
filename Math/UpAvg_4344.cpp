#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 테스트 케이스 입력값
    int test; cin >> test;

    while(test--) {
        double people; cin >> people;
        vector<int> arr;
        
        int sum = 0; 
        // 점수 입력값
        for(int i = 0; i < people; i++) {
            int score; cin >> score;
            sum += score;
            arr.push_back(score);
        }
        
        double avg = double(sum) / people;
        
        // 평균 구하기
        int upPerson = 0;
        for(int i = 0; i < people; i++) {
            if(arr[i] > avg) upPerson++;
        }
        
        // 출력문
        cout << fixed;
        cout.precision(3);
        cout << double(upPerson * 100) / people << '%' << '\n';
    }
    return 0;
}