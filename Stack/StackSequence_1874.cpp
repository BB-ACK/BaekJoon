#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sequence(vector<int> &arr, vector<char> &result) {
    int cur = 1;
    vector<int> seq;

    for(int i = 0;  i < arr.size(); i++) {
        while(arr[i] >= cur) {
            seq.push_back(cur++);
            result.push_back('+');
        }

        if(seq.back() != arr[i]) { // pop하는 원소가 다르면 NO
            return "NO";
        }
        else {
            seq.pop_back();
            result.push_back('-');
        }

    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int len; cin >> len;
    vector<int> arr(len);
    vector<char> result; // 결과출력을 위한 벡터

    // 수열 입력
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    string s = sequence(arr, result);

    if(s == "NO") {
        cout << s;
    }
    else {
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << '\n';
    }

    return 0;
}