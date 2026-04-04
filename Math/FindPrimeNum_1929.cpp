#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 출력 최적화
    ios::sync_with_stdio(false);
    cout.tie(0);

    int min, max; cin >> min >> max;
    vector<bool> find(max, false); // 방문처리
    vector<int> primeNum; // 소수 배열

    // 2부터 쭉 배수를 소거한다
    for(int i = 2; i <= max; i++) {
        // 방문하지 않은 경우(소수) 
        if(find[i] == false) primeNum.push_back(i);

        int mul = 2; // 곱할 수 
        while(i * mul <= max) {
            find[i*mul] = true;
            mul++;
        }
    }

    // 출력문
    for(int i = 0; i < primeNum.size(); i++) {
        if(primeNum[i] >= min) 
            cout << primeNum[i] << '\n';
    }
    return 0;
}