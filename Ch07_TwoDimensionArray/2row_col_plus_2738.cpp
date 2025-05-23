#include <iostream>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    // 2차원 동적 배열 선언
    int **arr1 = new int *[row];
    int **arr2 = new int *[row];

    for(int i = 0; i < row; i++) {
        arr1[i] = new int[col];
        arr2[i] = new int[col];
    }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr1[i][j];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr2[i][j];
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
        cout << endl;
    }
    
    // 동적 배열 메모리 해제
    for(int i = 0; i < row; i++) {
        delete[] arr1[i];
        delete[] arr2[i];
    }
    
    delete[] arr1;
    delete[] arr2;
    return 0;
}