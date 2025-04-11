#include <iostream>
#include <vector>
using namespace std;

void yosepuse(vector<int> arr, int k) {
    vector<int> result;
    int idx = 0;

    while(!arr.empty()) {
        idx = (idx + k-1) % arr.size();
        result.push_back(arr[idx]); 
        arr.erase(arr.begin() + idx);
    }

    // 결과 출력문
    cout << "<" << result[0];
    for(int i = 1; i < result.size(); i++) {
        cout << ", " << result[i];
    }
    cout << ">";    
}

int main() {
    int num, k;
    cin >> num >> k;
    vector<int> arr;
    
    for(int i = 0; i < num; i++)
        arr.push_back(i+1);

    yosepuse(arr, k);    

    return 0;
}