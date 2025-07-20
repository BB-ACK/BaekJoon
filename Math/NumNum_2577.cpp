#include <iostream>
#include <vector>
using namespace std;

void countNum(int num) {
    vector<int> arr(10, 0);

    while(num > 0) {
        int idx = num % 10;
        arr[idx]++;

        num = num / 10;
    }


    for(int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }

}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    countNum(a*b*c);

    return 0;
}