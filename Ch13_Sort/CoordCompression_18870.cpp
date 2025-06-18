// 머지 소트를 활용한 문제 접근
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int idx;
    int x;
};

bool cmp(coordinate a, coordinate b) {
    return a.idx < b.idx;
}

// 합병하는 함수
void merge(vector<coordinate> &arr, int start, int mid, int end) {
    vector<coordinate> copy = arr; // 정렬 비교를 위한 복사본
    int idxL = start; // 왼쪽 배열 시작 idx
    int idxR = mid+1; // 오른쪽 배열 시작 idx
    int idx = start; // 본체 idx    
    
    while(idxL <= mid && idxR <= end) {
        if(copy[idxL].x <= copy[idxR].x) {
            arr[idx] = copy[idxL];
            idx++, idxL++;
        }       
        else {
            arr[idx] = copy[idxR];
            idx++, idxR++;
        }
    }
    
    // 나머지 삽입
    while(idxL <= mid) {
        arr[idx] = copy[idxL];
        idx++, idxL++;
    }
    
    while(idxR <= end) {
        arr[idx] = copy[idxR];
        idx++, idxR++;
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
    arr[0].x = 0; // 초기화

    for(int i = 1; i < arr.size(); i++) {
        if(copy[i].x == copy[i-1].x)
            arr[i].x = arr[i-1].x;

        else arr[i].x = arr[i-1].x + 1;
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
    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i].x << " ";
    }

    return 0;
}