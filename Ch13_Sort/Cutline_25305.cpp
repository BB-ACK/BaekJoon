#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > arr[idx])
                idx = j;
        }
        swap(arr[i], arr[idx]);
    }
}

int main() {
    int num, cutline;
    cin >> num >> cutline;
    
    vector<int> score(num);

    for(int i = 0; i < num; i++) {
        cin >> score[i];
    }

    selectionSort(score);
   
    cout << score[cutline-1];

    return 0;
}