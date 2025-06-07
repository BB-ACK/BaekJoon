#include <iostream>
#include <deque>
using namespace std;

class MaxHeap {
private:
    deque<int> arr;
    int size;

public:
    // 생성자
    MaxHeap() {
        this->arr.push_back(0); // 완전이진트리의 0번 인덱스 사용 x
        this->size = 0;
    }

    void insert(int e) {
        this->arr.push_back(e);
        this->size++;

        this->upHeap(e);
    }

    // 원소 삽입 시 자리를 찾는 함수
    void upHeap(int e) {
        int idx = this->size; // 시작 인덱스 위치 
        
        // 루트가 아니고 더 큰 경우에만
        while(idx != 1 && e > this->arr[idx/2]) {
            this->arr[idx] = this->arr[idx/2]; // 부모가 내려감
            idx /= 2;
        }

        this->arr[idx] = e;
    }

    int remove() {
        int ret = this->arr[1]; 
        this->arr[1] = this->arr.back();
        this->arr.pop_back();
        this->size--;

        this->downHeap();

        return ret;
    }

    // 원소 제거시 올라온 원소를 내리는 함수
    void downHeap() {
        int key = this->arr[1];
        int idx = 1; // 내려가기 위한 시작위치 : 루트
        int ci = 2; // 자식 노드 인덱스

        while(this->size >= ci) { // 자식 노드가 존재해야함
            // 자식 노드가 둘이고 오른쪽 노드가 더 크다면 -> 더 높은 것을 올려야힘
            if(this->size > ci && this->arr[ci + 1] > this->arr[ci]) {
                ci++;
            }

            if(key < this->arr[ci]) {
                this->arr[idx] = this->arr[ci];
                idx = ci;
                ci *= 2;
            }
            else break;
        }

        this->arr[idx] = key;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MaxHeap arr;
    int num; cin >> num;
    
    // 입력문
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            int e; cin >> e;
            arr.insert(e);
        }
    }

    // 출력문
    for(int i = 0; i < num; i++) {
        int result = arr.remove(); 
        if(i == num - 1)
            cout << result; 
    }
    return 0;
}