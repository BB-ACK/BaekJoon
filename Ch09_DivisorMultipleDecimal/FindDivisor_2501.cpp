#include <iostream>
using namespace std;

int countDivisor(int num, int cnt) {
    
    for(int i = 1; i <= num; i++) {
        if(num % i == 0)
            cnt--;

        if(cnt == 0)
            return i;
    }
    
    return 0;
}

int main() {
    int num, cnt; 
    cin >> num >> cnt;

    cout << countDivisor(num, cnt) << endl;

    return 0;
}