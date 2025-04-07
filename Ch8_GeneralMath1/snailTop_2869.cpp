#include <iostream>
using namespace std;

int ontheTop(int up, int down, int top) {
    int cur = 0;

    for(int i = 1; ; i++) {
        cur += up;
        
        if(cur >= top)
            return i;
        else 
            cur -= down;
    }
}

int main() {
    int up, down, top;
    cin >> up >> down >> top;

    cout << ontheTop(up, down, top);

    return 0;
}