#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len; cin >> len;
    vector<int> arr(10000);

    int max = -1;
    for(int i = 0; i < len; i++) {
        int num; cin >> num;
        arr[num]++;

        if(num > max)
            max = num;
    }

    for(int i = 0; i <= max; i++)
        while(arr[i] != 0) {
            cout << i << '\n';
            arr[i]--;
        }

    return 0;
}