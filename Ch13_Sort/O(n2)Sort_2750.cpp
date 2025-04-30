#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int idx = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[idx])
                idx = j;
        }
        swap(arr[i], arr[idx]);
    }
}

int main() {
    int num; cin >> num;
    vector<int> arr;

    while(num--) {
        int e; cin >> e;
        arr.push_back(e);
    }

    selectionSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}