#include <iostream>
#include <stack>
using namespace std;

int findDecimal(stack<int> arr) {
    int find = 0;
    while(!arr.empty()) {
        int tmp = arr.top();
        if(tmp == 2) {
            find++;
            arr.pop();
            continue;
        }
        
        for(int i = 2; i < tmp; i++) {
            if(tmp % i == 0)
                break;
            
            if(i == tmp-1)
                find++;
        }

        arr.pop();
    }

    return find;
}

int main() {
    int test; cin >> test;
    stack<int> arr;

    while(test--) {
        int num; cin >> num;
        arr.push(num);
    }

    cout << findDecimal(arr) << endl;

    return 0;
}