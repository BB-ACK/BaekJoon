#include <iostream>
using namespace std;

int main() {
    int test;  
    cin >> test;

    double *arr = new double[test];
    double max = 0;

    // 점수 입력
    for(int i = 0; i < test; i++) {
        cin >> arr[i];

        if(arr[i] > max)
            max = arr[i];
    }

    double sum = 0;

    for(int i = 0; i < test; i++) {
        double num = arr[i] / max * 100;
        sum += num;
    }

    cout << sum / test; 
    delete[] arr;
    return 0;
}