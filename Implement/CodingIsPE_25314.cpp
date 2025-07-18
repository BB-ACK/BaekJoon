#include <iostream>
#include <string>
using namespace std;

void print(int num) {
    int repeat = num / 4;

    for(int i = 0; i < repeat; i++) {
        cout << "long ";
    }

    cout << "int";
}

int main() {
    int num; cin >> num;

    print(num);
}