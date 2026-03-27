#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    int num; cin >> num;
    
    for(int i = num; i > 0; i--) {
        cout << i << '\n';
    }
    
    return 0;
}