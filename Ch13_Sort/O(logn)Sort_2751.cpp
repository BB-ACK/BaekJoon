#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, vector<int> left, vector<int> right, int low) {
    int i = 0; int j = 0;

    while(i < left.size() && j < right.size()) {
        if(left[i] > right[j]) {
            arr[low] = right[j];
            j++; low++;
        }
        else {
            arr[low] = left[i];
            i++; low++;
        }
    }

    while(i < left.size()) {
        arr[low] = left[i];
        i++; low++;
    }
    while (j < right.size()) {
        arr[low] = right[j];
        j++; low++;
    }
}

vector<int> mergeSort(vector<int> &arr, int low, int high) {
    // base case
    if(low >= high) 
        return vector<int>(arr.begin() + low, arr.begin() + high+1);
    
    int mid = (low + high) / 2;
    
    vector<int> left = mergeSort(arr, low, mid);
    vector<int> right = mergeSort(arr, mid+1, high);
    merge(arr, left, right, low);

    return vector<int> (arr.begin() + low, arr.begin() + high+1);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num; cin >> num;
    vector<int> arr(num);

    for(int i = 0; i < num; i++)
        cin >> arr[i];

    mergeSort(arr, 0, num-1);

    for(int i = 0; i < num; i++)
        cout << arr[i] << '\n';
    
    return 0;
}