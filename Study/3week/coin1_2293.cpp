#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &usingCoin, vector<int> &arr, int &kind, int &coin) {
    // bottom-up
    for(int i = 0; i < kind; i++) {
        for(int j = usingCoin[i]; j <= coin; j++) {
            arr[j] += arr[j - usingCoin[i]]; 
        }
    }

    return arr[coin];
}

int main() {
    int kind, coin;
    cin >> kind >> coin;
    // 코인 종류 벡터
    vector<int> usingCoin;
    vector<int> arr(coin+1, 0);


    // 코인 대입
    for(int i = 0; i < kind; i++) {
        int tmp; cin >> tmp;
        usingCoin.push_back(tmp);
    }

    // 초기화
    arr[0] = 1; // 0원을 만드는 방법은 1개 뿐

    cout << find(usingCoin, arr, kind, coin);

    return 0;
}