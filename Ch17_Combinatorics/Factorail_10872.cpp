#include <iostream>
using namespace std;

int rFac(int num) {
    if(num == 0 || num == 1) 
        return 1;

    return num * rFac(num - 1);
}

int main() {
    int num; cin >> num;

    cout << rFac(num);
    
    return 0;
}