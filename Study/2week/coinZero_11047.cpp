#include <iostream>
#include <vector>
using namespace std;

int total(vector<int> &coin, int change, int kind) {

    int i = kind - 1;
    // base case
    if(change == 0) 
        return 0;

    for(; i > 0; i--) {
        if(change - coin[i] >= 0) {
            break;
        }
    }
    
    return 1 + total(coin, change - coin[i], i+1);
}

int main() {
    int kind, money;
    cin >> kind >> money;
    vector<int> coin(kind);

    for(int i = 0; i < kind; i++) {
        cin >> coin[i];
    }

    cout << total(coin, money, kind) << endl;

    return 0;
}