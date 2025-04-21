#include <iostream>
using namespace std;

int main() {
    int num; cin >> num;
    
    while(num != 1) {
        int i = 2;
        while(1) {
            if(num % i == 0){
                cout << i << endl;
                num /= i;
                break;
            }
            i++;
        }
    }
    return 0;
}