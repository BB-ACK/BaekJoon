#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[idx])
                idx = j;
        }
        swap(arr[i], arr[idx]);
    }
}

int main() {
    vector<int> arr;
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        int num; cin >> num;
        arr.push_back(num);
        sum += num;
    }
    selectionSort(arr);

    // 평균값
    cout << sum / 5 << '\n';
    cout << arr[2];
    
    return 0;
}

