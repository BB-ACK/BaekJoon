#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void chickenSort(vector<int> &arr, int start, int end, int group) {
    // 현재 구간 크기
    int size = end - start + 1;

    // base case
    if(size <= group) {
        sort(arr.begin() + start, arr.begin() + end + 1); // 왼쪽 정렬
        return;
    }

    int mid = start + (end - start) / 2; // 중점 찾기

    // 분할을 위한 중점
    chickenSort(arr, start, mid, group);
    chickenSort(arr, mid+1, end, group);
}

int main() {
    int num; cin >> num;
    vector<int> arr(num);

    for(int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int people; cin >> people;
    
    int group = num / people; // 결국 문제에서 나타낸 것은 몇 개의 그룹으로 나누어졌을 때 상황임

    chickenSort(arr, 0, num - 1, group);

    for(int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}