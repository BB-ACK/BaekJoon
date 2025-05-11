#include <iostream>
using namespace std;

int main() {
    int count, max = 0;

    int arr[9];

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];

        if(arr[i] > max) {
            count = i + 1;
            max = arr[i];
        }
    }

    cout << max << endl;
    cout << count;
    return 0;
}