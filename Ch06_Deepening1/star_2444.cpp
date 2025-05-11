#include <iostream> 
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            if(j >= n-1-i && j <= n-1+i)
                cout << "*";
            else if(j <= n-1-i)
                cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < 2*n-1; i++){
        cout << "*";
    }

    for(int i = 0; i < n-1; i++) {
        cout << endl;
        for(int j = 0; j < 2*n-1; j++) {
            if(j >= i+1 && j < 2*n-2-i)
                cout << "*";
            else if(j <= i)
                cout << " ";
        }
    }
    return 0;
}