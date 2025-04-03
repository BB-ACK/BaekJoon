#include <iostream>
#include <vector>
using namespace std;

// 거스름돈 4종류
int money[4] = {25, 10, 5, 1};

vector<int> change(int cent) {
    vector<int> result; // 거스름돈 종류를 저장할 배열

    // 거스름 돈은 4종류
    for(int i = 0; i < 4; i++) {
        result.push_back(cent / money[i]);
        cent %= money[i];
    }

    return result;
}

int main() {
    int test; cin >> test;

    while(test--) {
        int cent; cin >> cent;

        vector<int> result = change(cent);

        for(int i = 0; i < 4; i++){
            cout << result[i] << " ";
        }

        cout << endl;
    }

    return 0;
}