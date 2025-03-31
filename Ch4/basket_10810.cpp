#include <iostream>
using namespace std;

int main() {
    int num, test;
    cin >> num >> test;

    int *basket = new int[num];

    for(int i = 0; i < num; i++) 
        basket[i] = 0;

    while(test--) {
        int i, j, k;
        cin >> i >> j >> k;

        for(int s = i-1; s <= j-1; s++) 
            basket[s] = k;
    }

    for(int i = 0; i < num; i++) {
        cout << basket[i] << " ";
    }

    delete[] basket;

    return 0;
}