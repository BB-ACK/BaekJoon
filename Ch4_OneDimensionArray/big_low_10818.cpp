#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    int *num = new int[test];
    int max, min;

    for(int i = 0; i < test; i++) {
        cin >> num[i];
    
        if(i == 0) {
            max = num[i];
            min = num[i];
            continue;
        }

        if(num[i] >= max)
            max = num[i];
        else if(num[i] < min)
            min = num[i];
    }

    cout << min << " " << max;
 
    delete[] num;

    return 0;
}