#include <iostream>
#include <vector>
using namespace std;

vector<int> zeroSum(int element, vector<int> &arr) {
    if(element == 0) {
        arr.pop_back();
        return arr;
    }
    
    arr.push_back(element);
    return arr;
} 

int main() {
    int test; cin >> test;
    vector<int> arr;

    while(test--) {
        int num; cin >> num;
        zeroSum(num, arr);
    }

    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
        sum += arr[i];

    cout << sum << endl;

    return 0;
}