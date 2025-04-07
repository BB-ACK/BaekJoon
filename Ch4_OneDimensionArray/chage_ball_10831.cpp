#include <iostream>
using namespace std;

int main() {
    int test, num;
    cin >> num >> test;

    int *basket = new int[num];

    for(int i = 0; i < num; i++) 
        basket[i] = i+1;

    while(test--) {
        int a, b, temp;
        cin >> a >> b;

        temp = basket[a-1];
        basket[a-1] = basket[b-1];
        basket[b-1] = temp;
    }

    for(int i = 0; i < num; i++)
        cout << basket[i] << " ";

    delete[] basket;
    return 0;
}