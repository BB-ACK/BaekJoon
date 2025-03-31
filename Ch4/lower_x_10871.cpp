#include <iostream>
using namespace std;

int main() {
    int test, x;
    cin >> test >> x;

    int *num = new int[test];

    for(int i = 0; i < test; i++) {
        cin >> num[i];

        if(num[i] < x)
            cout << num[i] << " ";
    }

    delete[] num;
    
    return 0;
}