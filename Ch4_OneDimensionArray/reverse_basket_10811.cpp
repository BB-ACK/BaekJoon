#include <iostream>
using namespace std;

int main() {
    int num, test;
    cin >> num >> test;

    int *basket = new int[num];
    
    // 배열 초기화
    for(int i = 0; i < num; i++) 
        basket[i] = i+1;

    for(int i = 0; i < test; i++) {
        int a, b;
        cin >> a >> b;

        // 배열의 순서 뒤집기
        for(int i = 0; i < ((b-a) / 2) + 1; i++) {
            int temp = basket[(a-1)+i];
            basket[(a-1)+i] = basket[(b-1)-i];
            basket[(b-1)-i] = temp;
        }
    }

    for(int i = 0; i < num; i++)
        cout << basket[i] << " ";

    delete[] basket;
    return 0;
}