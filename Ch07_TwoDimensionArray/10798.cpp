#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[5][16];

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        int len = strlen(arr[i]);
        for(int j = len; j < 15; j++) {
            arr[i][j] = '\0';
        }
    }

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if(arr[j][i] == '\0')
                cout << "";
            else    
                cout << arr[j][i];
        }

    }
    return 0;
}