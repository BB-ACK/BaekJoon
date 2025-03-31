#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(double a, double b) {
    return a < b;
}

int main() {
    int num; cin >> num;
    vector<double> arr;

    cout << fixed;
    cout.precision(3);
    
    while(num--) {
        double score; cin >> score;
        arr.push_back(score);
    }
    
    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < 7; i++)
        cout << arr[i] << endl;

    return 0;
}