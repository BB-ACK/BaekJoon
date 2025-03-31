#include <iostream>
#include <string>
using namespace std;

int conversion(string num, int jin) {
    int sum = 0;
    int tmp = 1;
    for(int i = num.length()-1; i >= 0; i--) {
        if(int(num[i]) >= 65) {
            sum += (int(num[i]) - 55) * tmp;
        }
        else {
            sum += (int(num[i]) - 48) * tmp;
        }
        tmp *= jin;
    }

    return sum;
}

int main() {
    string num; cin >> num;
    int jin; cin >> jin;

    cout << conversion(num, jin);

    return 0;
}