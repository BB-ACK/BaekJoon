#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findFraction(int count) {
    vector<vector<string>> arr(10);

    int i = 0;

    while(count--) {
        // 인덱스 값이 더 크게 되면 추가 할당
        if(arr.size()-1 < i)
            arr.resize(i+1);
        
        if(arr[i].empty()) {
            arr[i].push_back(to_string(i+1) + "/1");
            if (count == 0)
                cout << arr[i].back();
            i = 0;
        }
        else {
            arr[i].push_back(to_string(i+1) + "/" + to_string(arr[i].size() + 1));
            if (count == 0)
                cout << arr[i].back();
            i++;
        }
        
    }   
}

int main() {
    int count; cin >> count;

    findFraction(count);

    return 0;
}