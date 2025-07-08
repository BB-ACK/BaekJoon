#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int verification(vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int cur = pow(arr[i], 2);
        sum += cur;
    }

    return sum % 10;
}

int main() {
    vector<int> arr;
    int num;

    for(int i = 0; i < 5; i++) {
        cin >> num;
        arr.push_back(num);
    }

    cout << verification(arr);
    
    return 0;
}