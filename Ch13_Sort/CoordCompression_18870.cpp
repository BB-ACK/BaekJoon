// 머지 소트를 활용한 문제 접근
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int idx; // 기존 인덱스
    int x; 
};

// 합병하는 함수
void merge(vector<coordinate> &arr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    vector<coordinate> temp; // 결과를 위한 임시용

    // 병합
    while (left <= mid && right <= end) {
        if (arr[left].x <= arr[right].x) {
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }

    // 왼쪽 나머지
    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    // 오른쪽 나머지
    while (right <= end) {
        temp.push_back(arr[right++]);
    }

    // 결과 덮어쓰기
    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

// 좌표계 정렬하는 함수
void mergeSort(vector<coordinate> &arr, int start, int end) {
    int mid = (end + start) / 2;

    // base case
    if(start >= end)
        return;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

// 압축하는 함수
void compression(vector<coordinate> &arr) {
    vector<coordinate> copy = arr; // 정렬을 위한 복사본
    int count = -1;

    // 첫 번째 초기화
    coordinate coord = copy[0];
    arr[coord.idx].x = ++count;

    for(int i = 1; i < arr.size(); i++) {
        coord = copy[i];
        if(copy[i].x == copy[i-1].x) 
            arr[coord.idx].x = count;
        else
            arr[coord.idx].x = ++count;
    }
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int len; cin >> len;

    vector<coordinate> arr;
    coordinate coord;
    for(int i = 0; i < len; i++) {
        coord.idx = i;
        cin >> coord.x;
        arr.push_back(coord);    
    }

    mergeSort(arr, 0, len-1);
    compression(arr);

    // 출력문
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i].x << " ";
    }

    return 0;
}