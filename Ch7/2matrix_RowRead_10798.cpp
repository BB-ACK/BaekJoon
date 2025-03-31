#include <iostream>
using namespace std;

int main() {
    char arr[5][15];
    int maxCount = 0;
    int maxWord_idx;

    for(int i = 0; i < 5; i++) {
        int currentCount = 0;
        cin.getline(arr[i], 15);
        for(int j = 0; arr[i][j] != '\0'; j++) {
            currentCount++;
        }
        if(currentCount > maxCount) {
            maxWord_idx = i;
            maxCount = currentCount;

        }
    }
    cout << endl;
    
    int i = 0, j = 0;
    for(; arr[maxWord_idx][j] != '\0'; j++) {
        for(; i < 5; i++) {
            cout << arr[i][j];
            if(i == 4) {
                i = 0;
                break;
            }
        }
    }
    return 0;
}