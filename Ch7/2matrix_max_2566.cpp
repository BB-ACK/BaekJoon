#include <iostream>
using namespace std;

int main() {
    int arr[9][9];
    int max = 0, idx_row, idx_col;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> arr[i][j];

            if(arr[i][j] >= max) {
                max = arr[i][j];
                idx_row = i+1;
                idx_col = j+1;
            }
        }
    }

    cout << max << endl;
    cout << idx_row << " " << idx_col;
    return 0;
}