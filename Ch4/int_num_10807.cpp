#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    int *num = new int[test];

    for(int i = 0; i < test; i++){
        int input;
        cin >> input;

        num[i] = input;
    }

    int find_num;
    cin >> find_num;

    int count = 0;
    for(int i = 0; i < test; i++) {
        if(num[i] == find_num)
            count++;
    }

    cout << count;

    delete[] num;

    return 0;
}